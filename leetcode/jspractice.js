/* 
Palindromes are words that are the same forward or backward. For example, 
the words "noon" and "kayak" are a palindromes.
 
Write a function to check if a lowercased string of letters is a palindrome. 
If the word is palindrome, return true. If it isn't, return false.

Example input: "motorbike"
Example output: false

Example input: "rotator" 
Example output: true
*/

function isPalindrome(str){
    return str === str.split("").reverse().join("")
}

// Test your function
console.log(isPalindrome("abba"));
console.log(isPalindrome("civic"));
console.log(isPalindrome("octopus"));
console.log(isPalindrome("pumpkins"));
console.log(isPalindrome("madam"));


/*  
Grandpa's hand isn't as steady as it used to be. You finally convinced him
to start using a password manager, but he accidentally typed and saved his
password with a bunch of extra characters. Help him recover his password by 
removing all the duplicate characters. 

Your function should take in a string of characters and return a
string with the duplicate characters removed. Assume that your input
is lowercased with only letters and numbers.  

Example input: "aabbccb1212"
Example output: "abc12"
*/ 
const password = "9338dsabbbadjdjdj2sdfdfdf282ff8fdsd888ss8cfgfg332q23"; 
 
function removeDupeChars(chars){
    const myarray = password.split("");
    let result = [];
    for (const char of myarray) {
        if (!result.includes(char)) {
            result.push(char);
        }
    }
    return result.join("");
}

console.log(removeDupeChars(password));
/* 
How often do the letters in your name repeat? 

Write a function that counts how many times each letter of your name
occurs. Your function should take in your first and last name and return
an object where the keys are each character in your name, and the value
is how many times that character appears in your name. 

Example input: "Peggy Porth"
Example output: {p: 2, e: 1, g: 2, y: 1, o: 1, r: 1, t: 1, h: 1}

Your function should NOT count spaces and should not be case sensitive (a
lowercase t and a capital T should be considered the same character).

*/ 

function countChars(str){
   let result = {};
   const mystr = str.split(" ").toLowerCase().join("");
   for (let i = 0; i < mystr.length; ++i) {
    if (!result[mystr[i]]) {
        result[mystr[i]] = 1;
    } else {
        result[mystr[i]] += 1;
    }
   }
   return result;
}

console.log(countChars("Peggy Porth"));

function removeDupesFromArray(arr){
    let result = [];
    for (let i = 0; i < arr.length; ++i) {
        if (!result.includes(arr[i])) {
            result.push(arr[i]);
        } else {
            continue;
        }
    }
    return result;
}

function flatten(arr) {
    let result = [];
    
    for (let myarry of arr) {
        if (Array.isArray(myarry)) {
            result.push(...flatten(myarry))
        } else {
            result.push(myarry)
        }
    }
    return result;
}

function sumArray(arr){
    let sum = 0;
    for (let i of arr) {
        sum += i;
    }
    return sum;
}