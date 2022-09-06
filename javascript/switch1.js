// This is for getting input from user
const readline = require('readline').createInterface
    ({
        input: process.stdin,
        output: process.stdout,
    });

function calculator(exp) {
    var splitArray = exp.split(" ");
    var num1 = Number(splitArray[0]);
    var operation = splitArray[1];
    var num2 = Number(splitArray[2]);

    // Switch checks the first matching case and 
    // if we don't add break it will run all the case statements below the matched case

    switch (operation) {
        case '+':
            answer = num1 + num2;
            console.log(answer);
        case '-':
            answer = num1 - num2;
            console.log(answer);
        case '*':
            answer = num1 * num2;
            console.log(answer);
        case '/':
            answer = num1 / num2;
            console.log(answer);
        default:
            answer = "Wrong Expression";
    }

    return answer;

}

readline.question(`Give Math Expression :- `, expression => {
    console.log(calculator(expression));
    readline.close();
});
