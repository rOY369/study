// Setup 
var collection =
{
    "2548":
    {
        "album": "Slippery When Wet",
        "artist": "Bon Jovi",
        "tracks":
            [
                "Let It Rock",
                "You Give Love a Bad Name"
            ]
    },
    "2468":
    {
        "album": "1999",
        "artist": "Prace",
        "tracks":
            [
                "1999",
                "Little Red Corvette"
            ]
    },
    "1245":
    {
        "artist": "Robert Palmer",
        "tracks": []
    },
    "5439":
    {
        "album": "ABBA Gold"
    }
};

// Keep a copy of Collection
var copyCollection = JSON.parse(JSON.stringify(collection));

function updateObject(id, property, value) {

    if (property == "tracks") {
        collection[id].tracks = collection[id].tracks || [];
        collection[id].tracks.push(value);
    }
    else {
        collection[id][property] = value;
    }

    return collection;
}

console.log(updateObject("5439", "tracks", "Heartless"));