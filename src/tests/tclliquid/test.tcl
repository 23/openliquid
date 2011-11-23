# Load the liquid extension for tcl
load ./../../../lib/tclliquid/libtclliquid[info sharedlibextension]

# Output coloring
proc set_color {color} {
    set result "\x1b\["
    append result $color
    append result "m"
    return $result
}

# Testing function
proc run_test {template expected variables} {
    set templates [list [list "test.liquid" $template]]
    
    puts "Rendering: $template"
    puts "Expecting: $expected"

    if { [catch {set result [liquid::render $templates "test.liquid" $variables]} errorMessage] } {
        puts $errorMessage
        puts "Status   : [set_color 31]Failure: $errorMessage[set_color 0]"
    } else {
        
        puts "Result   : $result"

        if { [string compare $result $expected] == 0 } {
            puts "Status   : [set_color 32]Success[set_color 0]"
        } else {
            puts "Status   : [set_color 31]Failure![set_color 0]"
        }
    }

    puts " "
}

# * Plain text pass-through
run_test "plain text" "plain text" [dict create]

# * Testing variables
run_test "\{\{\"string literal\"\}\}" "string literal" [dict create]
run_test "\{\{ \"string literal\" \}\}" "string literal" [dict create]
run_test "\{\{'string literal'\}\}" "string literal" [dict create]
run_test "\{\{ 'string literal' \}\}" "string literal" [dict create]
run_test "\{\{'string \"literal\"'\}\}" "string \"literal\"" [dict create]

run_test "{{10}}" "10" [dict create]
run_test "{{ 10 }}" "10" [dict create]

run_test "{{5.5}}" "5.5" [dict create]
run_test "{{ 5.5 }}" "5.5" [dict create]

#run_test "{{(1..5)}}" "1,2,3,4,5" [dict create]
#run_test "{{ (1..5) }}" "1,2,3,4,5" [dict create]

#run_test "{{(a..e)})" "a,b,c,d,e" [dict create]

run_test "{{ user }}" "Bob" [dict create "user" "Bob"]
run_test "{{ user.name }}" "Bob" [dict create "user" [dict create "name" "Bob"]]
run_test "{{ users\[0\] }}" "Bob" [dict create "users" [list "Bob"]]
run_test "{{ users\[0\].name }}" "Bob" [dict create "users" [list [dict create "name" "Bob"]]]

run_test "{{user|size}}" "3" [dict create "user" "Bob"]
run_test "{{ user | size }}" "3" [dict create "user" "Bob"]

run_test "{{user|size}}" "3" [dict create "user" [list "" "" ""]]
run_test "{{ user | size }}" "3" [dict create "user" [list "" "" ""]]

run_test "{{user|upcase}}" "BOB" [dict create "user" "Bob"]
run_test "{{ user | upcase }}" "BOB" [dict create "user" "Bob"]

run_test "{{user|downcase}}" "bob" [dict create "user" "Bob"]
run_test "{{ user | downcase }}" "bob" [dict create "user" "Bob"]

run_test "{{'<br/>'|escape}}" "&lt;br/&gt;" [dict create]
run_test "{{ '<br/>' | escape }}" "&lt;br/&gt;" [dict create]
run_test "{{ 'this & \"that\"' | escape }}" "this &amp; &quot;that&quot;" [dict create]

run_test "{{'I am the very model of a modern major general, really. I am the very model of a modern major general, really. I am the very model of a modern major general, really. I am the very model of a modern major general, really.'|truncate}}" "I am the very model of a modern major general, really. I am the very model of a modern major general..." [dict create]

run_test "{{user|truncate:2}}" "Bo..." [dict create "user" "Bob"]
run_test "{{ user | truncate:2 }}" "Bo..." [dict create "user" "Bob"]
run_test "{{ user | truncate: 2 }}" "Bo..." [dict create "user" "Bob"]

run_test "{{user|truncate:1,'-'}}" "B-" [dict create "user" "Bob"]
run_test "{{ user | truncate:1,'-' }}" "B-" [dict create "user" "Bob"]
run_test "{{ user | truncate: 1,'-' }}" "B-" [dict create "user" "Bob"]
run_test "{{ user | truncate: 1, '-' }}" "B-" [dict create "user" "Bob"]

run_test "{{'a b c d e f g h i j k l m n o p q r s t u v w x y z'|truncatewords}}" "a b c d e f g h i j k l m n o..." [dict create]
run_test "{{ 'a b c d e f g h i j k l m n o p q r s t u v w x y z' | truncatewords }}" "a b c d e f g h i j k l m n o..." [dict create]

run_test "{{'a b c d e f g h i j k l m n o p q r s t u v w x y z'|truncatewords:5}}" "a b c d e..." [dict create]
run_test "{{ 'a b c d e f g h i j k l m n o p q r s t u v w x y z' | truncatewords:5 }}" "a b c d e..." [dict create]

run_test "{{'a b c d e f g h i j k l m n o p q r s t u v w x y z'|truncatewords:5,'-'}}" "a b c d e-" [dict create]
run_test "{{ 'a b c d e f g h i j k l m n o p q r s t u v w x y z' | truncatewords: 5, '-' }}" "a b c d e-" [dict create]

run_test "{{'hello <b>bob</b>'|strip_html}}" "hello bob" [dict create]
run_test "{{ 'hello <b>bob</b>' | strip_html }}" "hello bob" [dict create]

run_test "{{src|strip_newlines}}" "hello bob old friend" [dict create "src" "\nhello \nbob \n\nold\n friend\n"]
run_test "{{ src | strip_newlines }}" "hello bob old friend" [dict create "src" "\nhello \nbob \n\nold\n friend\n"]

#run_test "{{(1..3)|join}}" "1 2 3" [dict create]
#run_test "{{ (1..3) | join }}" "1 2 3" [dict create]

#run_test "{{(1..3)|join:','}}" "1,2,3" [dict create]
#run_test "{{ (1..3) | join: ',' }}" "1,2,3" [dict create]

#run_test "{{c|sort}}" "1,2,3" [dict create "c" [list 2 1 3]]
#run_test "{{ c | sort }}" "1,2,3" [dict create "c" [list 2 1 3]]
#run_test "{{(1..3)|sort}}" "1,2,3" [dict create "c" [list 2 1 3]]
#run_test "{{ (1..3) | sort }}" "1,2,3" [dict create "c" [list 2 1 3]]

#run_test "{{c|reverse}}" "3,2,1" [dict create "c" [list 1 2 3]]
#run_test "{{ c | reverse }}" "3,2,1" [dict create "c" [list 1 2 3]]
#run_test "{{(1..3)|reverse}}" "3,2,1" [dict create "c" [list 1 2 3]]
#run_test "{{ (1..3) | reverse }}" "3,2,1" [dict create "c" [list 1 2 3]]

run_test "{{'bananas'|replace:'a'}}" "bnns" [dict create]
run_test "{{ 'bananas' | replace: 'a' }}" "bnns" [dict create]

run_test "{{'bananas'|replace:'a','u'}}" "bununus" [dict create]
run_test "{{ 'bananas' | replace: 'a', 'u' }}" "bununus" [dict create]

run_test "{{'bananas'|replace_first:'a'}}" "bnanas" [dict create]
run_test "{{ 'bananas' | replace_first: 'a' }}" "bnanas" [dict create]

run_test "{{'bananas'|replace_first:'a','u'}}" "bunanas" [dict create]
run_test "{{ 'bananas' | replace_first: 'a', 'u' }}" "bunanas" [dict create]

run_test "{{src|newline_to_br}}" "Hello,<br />\nHow are you?<br />\nI'm glad to here it." [dict create "src" "Hello,\nHow are you?\nI'm glad to here it."]
run_test "{{ src | newline_to_br }}" "Hello,<br />\nHow are you?<br />\nI'm glad to here it." [dict create "src" "Hello,\nHow are you?\nI'm glad to here it."]

run_test "{{ 'now' | date: '%Y' }}" [clock format [clock seconds] -format "%Y" -gmt t] [dict create]

run_test "{{src|date:'%m.%d.%Y'}}" "08.30.2008" [dict create "src" 1220054400]
run_test "{{ src | date: '%m.%d.%Y' }}" "08.30.2008" [dict create "src" 1220054400]
run_test "{{src|date:fmt}}" "08.30.2008" [dict create "src" 1220054400 "fmt" "%m.%d.%Y"]
run_test "{{ src | date: fmt }}" "08.30.2008" [dict create "src" 1220054400 "fmt" "%m.%d.%Y"]

#run_test "{{(1..3)|first}}" "1" [dict create]
#run_test "{{ (1..3) | first }}" "1" [dict create]
run_test "{{c|first}}" "1" [dict create "c" [list 1 2 3]]
run_test "{{ c | first }}" "1" [dict create "c" [list 1 2 3]]

#run_test "{{(1..3)|last}}" "3" [dict create]
#run_test "{{ (1..3) | last }}" "3" [dict create]
run_test "{{c|last}}" "3" [dict create "c" [list 1 2 3]]
run_test "{{ c | last }}" "3" [dict create "c" [list 1 2 3]]

run_test "{% assign myVar = 'VALUE' %}{{ myVar }}" "VALUE" [dict create]
run_test "{% assign myVar = 10 %}{{ myVar }}" "10" [dict create]
run_test "{% assign myVar = 5.5 %}{{ myVar }}" "5.5" [dict create]
#run_test "{% assign myVar = (1..3) %}{{ myVar }}" "1,2,3" [dict create]

run_test "{% capture myContent %}Good 'old content!{% endcapture %}Before {{ myContent }}" "Before Good 'old content!" [dict create]

run_test "{% case testVar %}{% when 1 %} One!{% when 2 %} Two!{%when 'test'%} Test!{%else%} Got me{%endcase%}" " One!" [dict create "testVar" 1]
run_test "{% case testVar %}{% when 1 %} One!{% when 2 %} Two!{%when 'test'%} Test!{%else%} Got me{%endcase%}" " Two!" [dict create "testVar" 2]
run_test "{% case testVar %}{% when 1 %} One!{% when 2 %} Two!{%when 'test'%} Test!{%else%} Got me{%endcase%}" " Test!" [dict create "testVar" "test"]
run_test "{% case testVar %}{% when 1 %} One!{% when 2 %} Two!{%when 'test'%} Test!{%else%} Got me{%endcase%}" " Got me" [dict create "testVar" ""]
run_test "{% case testVar %}{% when 1 %} One!{% when 2 %} Two!{%when 'test'%} Test!{%else%} Got me{%endcase%}" " Got me" [dict create]

run_test "{% comment %} content {%endcomment%}" "" [dict create]

run_test "{% cycle 'odd', 'even' %} {% cycle 'odd', 'even' %} {% cycle 'odd', 'even' %}" "odd even odd" [dict create]
run_test "{% cycle 'odd', 'even' %}{% cycle 'odd', 'even' %}{% cycle 'odd', 'even' %}" "oddevenodd" [dict create]
run_test "{% for item in (1..3) %}{{ item }}{% endfor %}" "123" [dict create]
run_test "{% for item in (1..3) %} {{ forloop.index }} {% endfor %}" " 1  2  3 " [dict create]
run_test "{% for item in (1..3) %} {{ forloop.index0 }} {% endfor %}" " 0  1  2 " [dict create]
run_test "{% for item in (1..3) %} {{ forloop.first }} {% endfor %}" " true  false  false " [dict create]
run_test "{% for item in (1..3) %} {{ forloop.last }} {% endfor %}" " false  false  true " [dict create]

run_test "{% if value == empty %}empty{% endif %}" "empty" [dict create]
run_test "{% if value %}not empty{% else %}empty{% endif %}" "empty" [dict create]
run_test "{% if value %}true{% else %}false{% endif %}" "false" [dict create "value" "false"]
run_test "{% if value %}true{% else %}false{% endif %}" "false" [dict create "value" "0"]
run_test "{% if value %}true{% else %}false{% endif %}" "false" [dict create "value" "f"]
run_test "{% if value %}true{% else %}false{% endif %}" "true" [dict create "value" "1"]
run_test "{% if value %}true{% else %}false{% endif %}" "true" [dict create "value" "true"]
run_test "{% if value %}true{% else %}false{% endif %}" "true" [dict create "value" "t"]

# Include test
set templates [list [list "test.liquid" "{% include 'simple' %}"] [list "simple" "simple INCLUDED!"]]
set expected "simple INCLUDED!"
set variables [dict create]
    
puts "Rendering: {% include 'simple' %}"
puts "Expecting: $expected"

if { [catch {set result [liquid::render $templates "test.liquid" $variables]} errorMessage] } {
    puts "Status   : [set_color 31]Failure: $errorMessage[set_color 0]"
} else {
        puts "Result   : $result"
    
    if { [string compare $result $expected] == 0 } {
            puts "Status   : [set_color 32]Success[set_color 0]"
    } else {
            puts "Status   : [set_color 31]Failure![set_color 0]"
    }
}

puts " "


