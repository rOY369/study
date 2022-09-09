var myObject =
{
    "name": "Nischay",
    "lastName": "Arora",
    "nickName": "Nishu",
    "pet name": "Rovo"
}

// Using dot notation to access properties 
console.log(myObject.name);

// Using bracket notation 
console.log(myObject["pet name"]);

// Deleting properties
delete myObject["pet name"];

// Adding properties
myObject["bark"] = "woof woof";

// Check if object has a property
console.log(myObject.hasOwnProperty("name"));
