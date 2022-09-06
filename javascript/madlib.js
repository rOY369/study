// Creat a function 
function wordBlanks (noun,adjective,verb,adverb)
{
    var result = "" ;
    result += "The " + adjective + " " + noun + " " + verb + " " + adverb + " ." ; 

    return result ;
}

console.log(wordBlanks("Human","Beautiful","cried","slowly")) ;