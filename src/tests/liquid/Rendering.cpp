#include <iostream>
#include <cstdlib>

#include <liquid/Template.hpp>

using namespace Liquid;

#define Failed(description, error)                                     \
    {                                                                  \
        std::cout << "\033[31m[FAILED]\033[0m " << description << ": " \
                  << error << std::endl;                               \
        Cleanup();                                                     \
        return EXIT_FAILURE;                                           \
    }

#define Passed(description)                         \
    {                                               \
        std::cout << "\033[32m[PASSED]\033[0m "     \
                  << description << std::endl;      \
    }

#define Cleanup()                               \
    delete data;

#define AssertRendering(_description, _template, _result)               \
    {                                                                   \
        Liquid::ParserError error;                                      \
        Liquid::RenderError renderError;                                \
        Liquid::Strainer strainer;                                      \
                                                                        \
        Liquid::Template* templ = Liquid::Template::Parse(_template,    \
                                                          strainer,     \
                                                          error);       \
                                                                        \
        if (templ == NULL)                                              \
            Failed(_description, error);                                \
                                                                        \
        std::string rendered;                                           \
                                                                        \
        if (templ->TryRender(data,                                      \
                             renderError,                               \
                             rendered))                                 \
        {                                                               \
            delete templ;                                               \
                                                                        \
            if (rendered != _result)                                    \
                Failed(_description,                                    \
                       "expected '" << _result << "' but got '" << rendered << "'"); \
                                                                        \
            Passed(_description);                                       \
        }                                                               \
        else                                                            \
        {                                                               \
            delete templ;                                               \
            Failed(_description, renderError);                          \
        }                                                               \
    }

int main()
{
    // * Initialize the rendering data
    HashFragment* data = new HashFragment();

    data->Set("username",
              new StringFragment("Bob"));

    HashFragment* userData = new HashFragment();
    data->Set("user",
              userData);

    userData->Set("name",
                  new StringFragment("Bobby"));

    ArrayFragment* usernames = new ArrayFragment();
    data->Set("usernames",
              usernames);
    
    usernames->Add(new StringFragment("Bob"));

    ArrayFragment* users = new ArrayFragment();
    data->Set("users",
              users);
    
    HashFragment* user0 = new HashFragment();
    user0->Set("name",
               new StringFragment("Bobby"));
    
    users->Add(user0);

    // * Plain text pass-through
    AssertRendering("Plain text pass-through",
                    "plain text",
                    "plain text");

    // * String literals
    AssertRendering("String literal #1",
                    "{{\"string literal\"}}",
                    "string literal");
    AssertRendering("String literal #2",
                    "{{ \"string literal\" }}",
                    "string literal");
    AssertRendering("String literal #3",
                    "{{'string literal'}}",
                    "string literal");
    AssertRendering("String literal #4",
                    "{{ 'string literal' }}",
                    "string literal");
    AssertRendering("String literal #5",
                    "{{'string \"literal\"'}}",
                    "string \"literal\"");
    AssertRendering("String literal #6",
                    "{{ 'string \"literal\"' }}",
                    "string \"literal\"");

    // * Integers
    AssertRendering("Integer #1",
                    "{{10}}",
                    "10");
    AssertRendering("Integer #2",
                    "{{ 10 }}",
                    "10");

    // * Floating point numbers
    AssertRendering("Floating point number #1",
                    "{{5.5}}",
                    "5.5");
    AssertRendering("Floating point number #2",
                    "{{ 5.5 }}",
                    "5.5");

    // * Root level variable
    AssertRendering("Root level variable #1",
                    "{{username}}",
                    "Bob");
    AssertRendering("Root level variable #2",
                    "{{ username }}",
                    "Bob");

    // * Nested variable
    AssertRendering("Nested variable #1",
                    "{{user.name}}",
                    "Bobby");
    AssertRendering("Nested variable #2",
                    "{{ user.name }}",
                    "Bobby");

    // * Indexed variable
    AssertRendering("Indexed variable #1",
                    "{{usernames[0]}}",
                    "Bob");
    AssertRendering("Indexed variable #2",
                    "{{ usernames[0] }}",
                    "Bob");

    // * Nested indexed variable
    AssertRendering("Nested indexed variable #1",
                    "{{users[0].name}}",
                    "Bobby");
    AssertRendering("Nested indexed variable #2",
                    "{{ users[0].name }}",
                    "Bobby");

    // * Assignment tag
    AssertRendering("{% assign .. %} #1",
                    "{% assign myVar = 'VALUE' %}.{{ myVar }}.",
                    ".VALUE.");
    AssertRendering("{% assign .. %} #2",
                    "{% assign myVar = 10 %}.{{ myVar }}.",
                    ".10.");
    AssertRendering("{% assign .. %} #3",
                    "{% assign myVar = 5.5 %}.{{ myVar }}.",
                    ".5.5.");
    AssertRendering("{% assign .. %} #4",
                    "{% assign myVar = 'foo' %}",
                    "");
    
    // * Capture tag
    AssertRendering("{% capture .. %} .. {% endcapture %} #1",
                    "{% capture myContent %}Good 'old content!{% endcapture %}Before {{ myContent }}",
                    "Before Good 'old content!");

    // * Case tag
    data->Set("testVar",
              new IntegerFragment(1));
    AssertRendering("{% case .. %} .. {% endcase %} #1",
                    "{% case testVar %}{% when 1 %}One!{% when 2 %}Two!{% when 'test' %}Test!{% else %}Got me{% endcase %}",
                    "One!");
    
    data->Set("testVar",
              new IntegerFragment(2));
    AssertRendering("{% case .. %} .. {% endcase %} #2",
                    "{% case testVar %}{% when 1 %}One!{% when 2 %}Two!{% when 'test' %}Test!{% else %}Got me{% endcase %}",
                    "Two!");

    data->Set("testVar",
              new StringFragment("test"));
    AssertRendering("{% case .. %} .. {% endcase %} #3",
                    "{% case testVar %}{% when 1 %}One!{% when 2 %}Two!{% when 'test' %}Test!{% else %}Got me{% endcase %}",
                    "Test!");

    data->Set("testVar",
              new NullFragment());
    AssertRendering("{% case .. %} .. {% endcase %} #4",
                    "{% case testVar %}{% when 1 %}One!{% when 2 %}Two!{% when 'test' %}Test!{% else %}Got me{% endcase %}",
                    "Got me");

    data->Set("testVar",
              NULL);
    AssertRendering("{% case .. %} .. {% endcase %} #5",
                    "{% case testVar %}{% when 1 %}One!{% when 2 %}Two!{% when 'test' %}Test!{% else %}Got me{% endcase %}",
                    "Got me");

    // * Comment tag
    AssertRendering("{% comment %} .. {% endcomment %} #1",
                    "{% comment %}This should not show up{% endcomment %}",
                    "");

    // * Raw tag
    AssertRendering("{% raw %} .. {% endraw %} #1",
                    "{% raw %}{% hello %} {{ you }}{% endraw %}",
                    "{% hello %} {{ you }}");

    // * For tag
    AssertRendering("{% for .. in ( .. ) %} .. {% endfor %} #1",
                    "{% for x in (1 .. 3) %}{{x}}{% endfor %}",
                    "123");
    AssertRendering("{% for .. in ( .. ) %} .. {% endfor %} #2",
                    "{% for x in (1 .. 5) %}{{forloop.first}} {% endfor %}",
                    "true false false false false ");
    AssertRendering("{% for .. in ( .. ) %} .. {% endfor %} #3",
                    "{% for x in (1 .. 5) %}{{forloop.last}} {% endfor %}",
                    "false false false false true ");
    AssertRendering("{% for .. in ( .. ) %} .. {% endfor %} #4",
                    "{% for x in (1 .. 5) %}{{forloop.odd}} {% endfor %}",
                    "true false true false true ");
    AssertRendering("{% for .. in ( .. ) %} .. {% endfor %} #5",
                    "{% for x in (1 .. 5) %}{{forloop.even}} {% endfor %}",
                    "false true false true false ");

    // * If statements
    AssertRendering("{% if condition %} .. {% endif %} #1",
                    "{% if true %}TRUE{% endif %}",
                    "TRUE");
    AssertRendering("{% if condition %} .. {% endif %} #2",
                    "{% if 1 == 1 %}TRUE{% endif %}",
                    "TRUE");
    AssertRendering("{% if condition %} .. {% endif %} #3",
                    "{% if 1 != 1 %}TRUE{% endif %}",
                    "");
    AssertRendering("{% if condition %} .. {% endif %} #4",
                    "{% if 1 > 1 %}TRUE{% endif %}",
                    "");
    AssertRendering("{% if condition %} .. {% endif %} #5",
                    "{% if 1 < 1 %}TRUE{% endif %}",
                    "");
    AssertRendering("{% if condition %} .. {% endif %} #6",
                    "{% if 1 <= 1 %}TRUE{% endif %}",
                    "TRUE");
    AssertRendering("{% if condition %} .. {% endif %} #7",
                    "{% if 1 >= 1 %}TRUE{% endif %}",
                    "TRUE");

    AssertRendering("{% if condition or condition %} .. {% endif %} #1",
                    "{% if 1 > 1 or 1 == 1 %}TRUE{% endif %}",
                    "TRUE");
    AssertRendering("{% if condition or condition %} .. {% endif %} #2",
                    "{% if 1 > 1 or 1 < 1 %}TRUE{% endif %}",
                    "");

    AssertRendering("{% if condition and condition %} .. {% endif %} #3",
                    "{% if 1 >= 1 and 1 == 1 %}TRUE{% endif %}",
                    "TRUE");
    AssertRendering("{% if condition and condition %} .. {% endif %} #4",
                    "{% if 1 > 1 and 1 < 1 %}TRUE{% endif %}",
                    "");

    // * If, else statements
    AssertRendering("{% if condition %} .. {% else %} .. {% endif %} #1",
                    "{% if true %}TRUE{% else %}FALSE{% endif %}",
                    "TRUE");
    AssertRendering("{% if condition %} .. {% else %} .. {% endif %} #2",
                    "{% if 1 == 1 %}TRUE{% else %}FALSE{% endif %}",
                    "TRUE");
    AssertRendering("{% if condition %} .. {% else %} .. {% endif %} #3",
                    "{% if 1 != 1 %}TRUE{% else %}FALSE{% endif %}",
                    "FALSE");
    AssertRendering("{% if condition %} .. {% else %} .. {% endif %} #4",
                    "{% if 1 > 1 %}TRUE{% else %}FALSE{% endif %}",
                    "FALSE");
    AssertRendering("{% if condition %} .. {% else %} .. {% endif %} #5",
                    "{% if 1 < 1 %}TRUE{% else %}FALSE{% endif %}",
                    "FALSE");
    AssertRendering("{% if condition %} .. {% else %} .. {% endif %} #6",
                    "{% if 1 <= 1 %}TRUE{% else %}FALSE{% endif %}",
                    "TRUE");
    AssertRendering("{% if condition %} .. {% else %} .. {% endif %} #7",
                    "{% if 1 >= 1 %}TRUE{% else %}FALSE{% endif %}",
                    "TRUE");

    AssertRendering("{% if condition or condition %} .. {% else %} .. {% endif %} #1",
                    "{% if 1 > 1 or 1 == 1 %}TRUE{% else %}FALSE{% endif %}",
                    "TRUE");
    AssertRendering("{% if condition or condition %} .. {% else %} .. {% endif %} #2",
                    "{% if 1 > 1 or 1 < 1 %}TRUE{% else %}FALSE{% endif %}",
                    "FALSE");

    AssertRendering("{% if condition and condition %} .. {% else %} .. {% endif %} #3",
                    "{% if 1 >= 1 and 1 == 1 %}TRUE{% else %}FALSE{% endif %}",
                    "TRUE");
    AssertRendering("{% if condition and condition %} .. {% else %} .. {% endif %} #4",
                    "{% if 1 > 1 and 1 < 1 %}TRUE{% else %}FALSE{% endif %}",
                    "FALSE");

    // * If, elsif, else statements
    data->Set("cond",
              new IntegerFragment(0));
    AssertRendering("{% if condition %} .. {% elsif condition %} .. {% else %} .. {% endif %} #1",
                    "{% if cond == 0 %}0{% elsif cond == 1 %}1{% elseif cond == 2 %}2{% else %}other{% endif %}",
                    "0");

    data->Set("cond",
              new IntegerFragment(1));
    AssertRendering("{% if condition %} .. {% elsif condition %} .. {% else %} .. {% endif %} #2",
                    "{% if cond == 0 %}0{% elsif cond == 1 %}1{% elseif cond == 2 %}2{% else %}other{% endif %}",
                    "1");

    data->Set("cond",
              new IntegerFragment(2));
    AssertRendering("{% if condition %} .. {% elsif condition %} .. {% else %} .. {% endif %} #3",
                    "{% if cond == 0 %}0{% elsif cond == 1 %}1{% elseif cond == 2 %}2{% else %}other{% endif %}",
                    "2");

    data->Set("cond",
              new IntegerFragment(4));
    AssertRendering("{% if condition %} .. {% elsif condition %} .. {% else %} .. {% endif %} #4",
                    "{% if cond == 0 %}0{% elsif cond == 1 %}1{% elseif cond == 2 %}2{% else %}other{% endif %}",
                    "other");

    // * Cleanup
    Cleanup();

    return EXIT_SUCCESS;
}
