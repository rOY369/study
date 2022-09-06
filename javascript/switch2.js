// Multiple input give same output in Switch

var v = 100;
switch (v) {
    case 1:
    case 2:
    case 3:
        answer = "Low";
        break;
    case 4:
    case 5:
    case 6:
        answer = "Mid";
        break;
    default:
        answer = "High";
        break;
}

console.log(answer);

