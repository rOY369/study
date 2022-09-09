// Setup
var contacts =
    [
        {
            "firstName": "Akira",
            "lastName": "Laine",
            "number": "0543236543",
            "likes": ["Pizza", "Coding", "Brownie Points"]
        },
        {
            "firstName": "Harry",
            "lastName": "Potter",
            "number": "0994372684",
            "likes": ["Hogwarts", "Magic", "Hagrid"]
        },
        {
            "firstName": "Sherlock",
            "lastName": "Holmes",
            "number": "0487345643",
            "likes": ["Intriguing Cases", "Violin"]
        },
        {
            "firstName": "Kristian",
            "lastName": "Vos",
            "number": "unknown",
            "likes": ["JavaScript", "Gaming", "Foxes"]
        }
    ];

// My code
function lookUpProfile(name, prop) {
    for (var i = 0; i < contacts.length; i++) {
        if (contacts[i].firstName == name) {
            if (contacts[i].hasOwnProperty(prop)) {
                return contacts[i][prop];
            }
            else {
                return "Invalid Property";
            }
        }
    }

    return "Invalid Name";
}

// Tutor's code
function lookUpProfileTutor(name, prop) {
    for (var i = 0; i < contacts.length; i++) {
        if (contacts[i].firstName === name) {
            return contacts[i][prop] || "Invalid Property"; // If no property then it returns second part of OR
        }
    }
    return "Invalid Name";
}

console.log(lookUpProfile("Harry", "number"));
console.log(lookUpProfileTutor("Nischay", "lastName"));