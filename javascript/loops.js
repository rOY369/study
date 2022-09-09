// For loops
for (i = 0; i <= 10; i += 2) {
    console.log(i);
}

// While loops
i = 0;
while (i < 10) {
    console.log(i);
    i += 2;
}

// Loop through an array
myArray = [1, 2, 3, 4, 6]
for (i = 0; i < myArray.length; i++) {
    console.log(myArray[i])
}

// Access nested arrays through nested loops
nestedArray = [[1, 2], [3, 4], [5, 6, 7]];
for (i = 0; i < nestedArray.length; i++) {
    product = 1;
    for (j = 0; j < nestedArray[i].length; j++) {
        product *= nestedArray[i][j];
    }
    console.log(product);
}

// Do while loops
// They always run the loop once before checking the condition 
var k = 0;
do {
    console.log(k, "This is run once before checking condition");
    k++;
}
while (k > 10);