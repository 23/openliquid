var targets = [{
    name: "null",
    code: "new NullFragment()"
},
{
    name: "empty",
    code: "new EmptyFragment()"
},
{
    name: "int(0)",
    code: "new IntegerFragment(0)"
},
{
    name: "int(1)",
    code: "new IntegerFragment(1)"
},
{
    name: "int(-1)",
    code: "new IntegerFragment(-1)"
},
{
    name: "float(0.0)",
    code: "new FloatFragment(0.0)"
},
{
    name: "float(0.1)",
    code: "new FloatFragment(0.1)"
},
{
    name: "float(1.0)",
    code: "new FloatFragment(1.0)"
},
{
    name: "float(-0.1)",
    code: "new FloatFragment(-0.1)"
},
{
    name: "float(-1.0)",
    code: "new FloatFragment(-1.0)"
},
{
    name: "hash",
    code: "new HashFragment()"
},
{
    name: "array()",
    code: "new ArrayFragment()"
},
{
    name: "array(..)",
    code: "new ArrayFragment(); reinterpret_cast<ArrayFragment*>(var12)->Add(new StringFragment(\"Test\"));"
},
{
    name: "bool(true)",
    code: "new BooleanFragment(true)"
},
{
    name: "bool(false)",
    code: "new BooleanFragment(false)"
},
{
    name: "string(\"\")",
    code: "new StringFragment(\"\")"
},
{
    name: "string(\"..\")",
    code: "new StringFragment(\"..\")"
},
{
    name: "string(\"t\")",
    code: "new StringFragment(\"t\")"
},
{
    name: "string(\"f\")",
    code: "new StringFragment(\"f\")"
}];

var targetCount = targets.length;

for (var lhsIndex = 0; lhsIndex < targetCount; lhsIndex++) {
    var lhs = targets[lhsIndex];

    // Throw out a heading
    $('body').append('<h2>' + lhs.name + '</h2>');

    var tableSource = '<table> \
  <tr> \
    <td>implicit</td> \
    <td colspan="6"><input type="checkbox" id="_' + lhsIndex + '_impl" /></td> \
  </tr> \
  <tr> \
    <th>&nbsp;</th> \
    <th>==</th> \
    <th>!=</th> \
    <th>&gt;</th> \
    <th>&lt;</th> \
    <th>&gt;=</th> \
    <th>&lt;=</th> \
  </tr>';

    for (var rhsIndex = lhsIndex; rhsIndex < targetCount; rhsIndex++) {
        var rhs = targets[rhsIndex];

        tableSource += '  <tr> \
    <td>' + rhs.name + '</td> \
    <td><input type="checkbox" id="_' + lhsIndex + '_' + rhsIndex + '_eq" size="1" /></td> \
    <td><input type="checkbox" id="_' + lhsIndex + '_' + rhsIndex + '_ne" size="1" /></td> \
    <td><input type="checkbox" id="_' + lhsIndex + '_' + rhsIndex + '_gt" size="1" /></td> \
    <td><input type="checkbox" id="_' + lhsIndex + '_' + rhsIndex + '_lt" size="1" /></td> \
    <td><input type="checkbox" id="_' + lhsIndex + '_' + rhsIndex + '_gte" size="1" /></td> \
    <td><input type="checkbox" id="_' + lhsIndex + '_' + rhsIndex + '_lte" size="1" /></td> \
  </tr>';
    }

    tableSource += '</table>';

    $('body').append(tableSource);
}

var defaults = ["#_0_0_eq", "#_0_1_ne", "#_0_2_ne", "#_0_3_ne", "#_0_4_ne", "#_0_5_ne", "#_0_6_ne", "#_0_7_ne", "#_0_8_ne", "#_0_9_ne", "#_0_10_ne", "#_0_11_ne", "#_0_12_ne", "#_0_13_ne", "#_0_14_ne", "#_0_15_ne", "#_0_16_ne", "#_0_17_ne", "#_0_18_ne", "#_1_1_eq", "#_1_2_ne", "#_1_3_ne", "#_1_4_ne", "#_1_5_ne", "#_1_6_ne", "#_1_7_ne", "#_1_8_ne", "#_1_9_ne", "#_1_10_ne", "#_1_11_eq", "#_1_12_ne", "#_1_13_ne", "#_1_14_ne", "#_1_15_eq", "#_1_16_ne", "#_1_17_ne", "#_1_18_ne", "#_2_2_eq", "#_2_2_gte", "#_2_2_lte", "#_2_3_ne", "#_2_3_lt", "#_2_3_lte", "#_2_4_ne", "#_2_4_gt", "#_2_4_gte", "#_2_5_eq", "#_2_5_gte", "#_2_5_lte", "#_2_6_ne", "#_2_6_lt", "#_2_6_lte", "#_2_7_ne", "#_2_7_lt", "#_2_7_lte", "#_2_8_ne", "#_2_8_gt", "#_2_8_gte", "#_2_9_ne", "#_2_9_gt", "#_2_9_gte", "#_2_10_ne", "#_2_11_ne", "#_2_12_ne", "#_2_13_ne", "#_2_14_eq", "#_2_15_ne", "#_2_16_ne", "#_2_17_ne", "#_2_18_ne", "#_3_3_eq", "#_3_3_gte", "#_3_3_lte", "#_3_4_ne", "#_3_4_gte", "#_3_5_ne", "#_3_5_gt", "#_3_5_gte", "#_3_6_ne", "#_3_6_gt", "#_3_6_gte", "#_3_7_eq", "#_3_7_gte", "#_3_7_lte", "#_3_8_ne", "#_3_8_gt", "#_3_8_gte", "#_3_9_ne", "#_3_9_gt", "#_3_9_gte", "#_3_10_ne", "#_3_11_ne", "#_3_12_ne", "#_3_13_eq", "#_3_14_ne", "#_3_15_ne", "#_3_16_ne", "#_3_17_ne", "#_3_18_ne", "#_4_4_eq", "#_4_4_gte", "#_4_4_lte", "#_4_5_ne", "#_4_5_lt", "#_4_5_lte", "#_4_6_ne", "#_4_6_lt", "#_4_6_lte", "#_4_7_ne", "#_4_7_lt", "#_4_7_lte", "#_4_8_ne", "#_4_8_lt", "#_4_8_lte", "#_4_9_eq", "#_4_9_gte", "#_4_9_lte", "#_4_10_ne", "#_4_11_ne", "#_4_12_ne", "#_4_13_ne", "#_4_14_eq", "#_4_15_ne", "#_4_16_ne", "#_4_17_ne", "#_4_18_ne", "#_5_5_eq", "#_5_5_gte", "#_5_5_lte", "#_5_6_ne", "#_5_6_lt", "#_5_6_lte", "#_5_7_ne", "#_5_7_lt", "#_5_7_lte", "#_5_8_ne", "#_5_8_gt", "#_5_8_gte", "#_5_9_ne", "#_5_9_gt", "#_5_9_gte", "#_5_10_ne", "#_5_11_ne", "#_5_12_ne", "#_5_13_ne", "#_5_14_eq", "#_5_15_ne", "#_5_16_ne", "#_5_17_ne", "#_5_18_ne", "#_6_6_eq", "#_6_6_gte", "#_6_6_lte", "#_6_7_ne", "#_6_7_lt", "#_6_7_lte", "#_6_8_ne", "#_6_8_gt", "#_6_8_gte", "#_6_9_ne", "#_6_9_gt", "#_6_9_gte", "#_6_10_ne", "#_6_11_ne", "#_6_12_ne", "#_6_13_eq", "#_6_14_ne", "#_6_15_ne", "#_6_16_ne", "#_6_17_ne", "#_6_18_ne", "#_7_7_eq", "#_7_7_gte", "#_7_7_lte", "#_7_8_ne", "#_7_8_gt", "#_7_8_gte", "#_7_9_ne", "#_7_9_gt", "#_7_9_gte", "#_7_10_ne", "#_7_11_ne", "#_7_12_ne", "#_7_13_eq", "#_7_14_ne", "#_7_15_ne", "#_7_16_ne", "#_7_17_ne", "#_7_18_ne", "#_8_8_eq", "#_8_8_gte", "#_8_8_lte", "#_8_9_ne", "#_8_9_gt", "#_8_9_gte", "#_8_10_ne", "#_8_11_ne", "#_8_12_ne", "#_8_13_ne", "#_8_14_eq", "#_8_15_ne", "#_8_16_ne", "#_8_17_ne", "#_8_18_ne", "#_9_9_eq", "#_9_9_gte", "#_9_9_lte", "#_9_10_ne", "#_9_11_ne", "#_9_12_ne", "#_9_13_ne", "#_9_14_eq", "#_9_15_ne", "#_9_16_ne", "#_9_17_ne", "#_9_18_ne", "#_10_10_eq", "#_10_11_ne", "#_10_12_ne", "#_10_13_ne", "#_10_14_ne", "#_10_15_ne", "#_10_16_ne", "#_10_17_ne", "#_10_18_ne", "#_11_11_eq", "#_11_12_ne", "#_11_13_ne", "#_11_14_ne", "#_11_15_ne", "#_11_16_ne", "#_11_17_ne", "#_11_18_ne", "#_12_12_eq", "#_12_13_ne", "#_12_14_ne", "#_12_15_ne", "#_12_16_ne", "#_12_17_ne", "#_12_18_ne", "#_13_13_eq", "#_13_14_ne", "#_13_15_ne", "#_13_16_ne", "#_13_17_eq", "#_13_18_ne", "#_14_14_eq", "#_14_15_ne", "#_14_16_ne", "#_14_17_ne", "#_14_18_eq", "#_15_15_eq", "#_15_15_gte", "#_15_15_lte", "#_15_16_ne", "#_15_16_lt", "#_15_16_lte", "#_15_17_ne", "#_15_17_lt", "#_15_17_lte", "#_15_18_ne", "#_15_18_lt", "#_15_18_lte", "#_16_16_eq", "#_16_16_gte", "#_16_16_lte", "#_16_17_ne", "#_16_17_lt", "#_16_17_lte", "#_16_18_ne", "#_16_18_lt", "#_16_18_lte", "#_17_17_eq", "#_17_17_gte", "#_17_17_lte", "#_17_18_ne", "#_17_18_gt", "#_17_18_gte", "#_18_18_eq", "#_18_18_gte", "#_18_18_lte"];

for (var def in defaults) {
    $(defaults[def]).attr('checked', 'checked');
}

var generateButton = $('<input type="button" value="Generate" />').appendTo($('body'));

function getBool(identifier) {
    return ($('#_' + identifier).is(':checked') ? 'true' : 'false');
}

var opComparator = {
    'eq': 'ConditionalEquals',
    'ne': 'ConditionalNotEquals',
    'gt': 'ConditionalGreaterThan',
    'lt': 'ConditionalLessThan',
    'gte': 'ConditionalGreaterThanOrEquals',
    'lte': 'ConditionalLessThanOrEquals'
};

var opComparatorInverse = {
    'eq': 'ConditionalEquals',
    'ne': 'ConditionalNotEquals',
    'gt': 'ConditionalLessThan',
    'lt': 'ConditionalGreaterThan',
    'gte': 'ConditionalLessThanOrEquals',
    'lte': 'ConditionalGreaterThanOrEquals'
};

var opCode = {
    'eq': '==',
    'ne': '!=',
    'gt': '>',
    'lt': '<',
    'gte': '>=',
    'lte': '<='
};

function evaluateSingle(lhs, rhs, lhsIndex, rhsIndex, op) {
    var expected = getBool(lhsIndex + '_' + rhsIndex + '_' + op);
    var description = lhs.name.replace(/"/g, '\\"') + ' ' + opCode[op] + ' ' + rhs.name.replace(/"/g, '\\"');

    result  = 'resultA = var' + lhsIndex + '->Compare(var' + rhsIndex + ', ' + opComparator[op] + ');\n';
    result += 'Assert(resultA == ' + expected + ',\n\
       "' + description + ' should have been ' + expected + '");\n';

    result += 'resultB = var' + rhsIndex + '->Compare(var' + lhsIndex + ', ' + opComparatorInverse[op] + ');\n';
    result += 'Assert(resultA == resultB,\n\
       "' + description + ' is inconsistent");\n';
    
    result += 'Passed("' + description + '");\n';
    
    return result;
}

var outputTextarea = undefined;

generateButton.click(function() {
    var result = '#include <liquid/Fragment.hpp>\n\
\n\
#include <iostream>\n\
#include <cstdlib>\n\
\n\
using namespace Liquid;\n\
\n\
#define Assert(expression, description)         \\\n\
    if (!(expression))                          \\\n\
    {                                           \\\n\
        std::cout << "\\033[31m[FAILED]\\033[0m " \\\n\
                  << description << std::endl;  \\\n\
                                                \\\n\
        Cleanup();                              \\\n\
        return EXIT_FAILURE;                    \\\n\
    }\n\
\n\
#define Passed(description)                     \\\n\
    std::cout << "\\033[32m[PASSED]\\033[0m "     \\\n\
                  << description << std::endl;\n\
\n';

    // Destruction of variables
    result += '// * Variable destruction\n\
#define Cleanup() \\\n';

    for (var lhsIndex = 0; lhsIndex < targetCount; lhsIndex++) {
        result += '    delete var' + lhsIndex + ';' + (lhsIndex + 1 == targetCount ? '' : '\\') + '\n';
    }

    result += '\n\
int main()\n\
{\n';
    
    // Initialization of variables
    result += '// * Variable initialization\n';
    
    for (var lhsIndex = 0; lhsIndex < targetCount; lhsIndex++) {
        var lhs = targets[lhsIndex];

        result += 'Fragment* var' + lhsIndex + ' = ' + lhs.code + ';\n';
    }

    result += '\n\
bool resultA, \n\
     resultB; \n\
\n';

    // For each variable
    for (var lhsIndex = 0; lhsIndex < targetCount; lhsIndex++) {
        var lhs = targets[lhsIndex];

        result += '// * Evaluating ' + lhs.name + '\n';

        // Implicit evaluation
        result += 'Assert(var' + lhsIndex + '->Compare(NULL, ConditionalImplicit) == ' + getBool(lhsIndex + '_impl') + ',\n\
       "Implicit test of ' + lhs.name.replace(/"/g, '\\"') + ' failed");\n';
        result += 'Passed("Implicit test of ' + lhs.name.replace(/"/g, '\\"') + '");\n';

        result += '\n';

        // Evaluate each possible RHS
        for (var rhsIndex = lhsIndex; rhsIndex < targetCount; rhsIndex++) {
            var rhs = targets[rhsIndex];
            
            result += '// Evaluating ' + lhs.name + ' against ' + rhs.name + '\n';
            
            result += evaluateSingle(lhs, rhs, lhsIndex, rhsIndex, 'eq');
            result += evaluateSingle(lhs, rhs, lhsIndex, rhsIndex, 'ne');
            result += evaluateSingle(lhs, rhs, lhsIndex, rhsIndex, 'lt');
            result += evaluateSingle(lhs, rhs, lhsIndex, rhsIndex, 'gte');
            result += evaluateSingle(lhs, rhs, lhsIndex, rhsIndex, 'lte');

            result += '\n';
        }
    }

    // End of code
    result += '    Cleanup();\n\
}\n';

    // Spit the output into the world
    if (outputTextarea === undefined)
        outputTextarea = $('<textarea style="width: 500px; height: 500px; display: block;"></textarea>').appendTo($('body'));

    outputTextarea.val(result);
});