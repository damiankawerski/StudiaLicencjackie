// zadanie 4

function generateRandom(min, max) {
    return  Math.floor(Math.random()*(max-min+1)+min);
}

function zadanie4() {
    let counter = 0;
    for (let i = 0 ; i < 10 ; i++) {
        let random = generateRandom(1, 20);
        if(random > 10) {
            counter++;
        }
    }
    //console.log(counter);
    if(counter > 5) {
        console.log("Udało się");
    } else {
        console.log("niestety nie");
    }
}

// zadanie 5
function checkPalindrom(txt) {
    reversed = txt.split("").reverse().join("");
    if (reversed == txt) {
        return true;
    } else {
        return false;
    }
}

// zadanie 6
function random(max) {
    return Math.floor(Math.random() * max)
}

function zadanie6() {
    let array = [];
    for(let i = 0 ; i < 20 ; i++) {
        array.push(random(10));
    }
    array.sort();
    let sum = 0;
    for(let i = 0 ; i < 20 ; i++) {
        sum += array[i];
    }
    console.log(sum/20);
}

// zadanie 7

function nums(array) {
    let result = [];
    let seen = [];
    let counter = 0;

    for (let cos of array) {
        if(seen.includes(cos)) {
            counter++;
            continue;
        }
        result.push(cos);
        seen.push(cos);
    }
    return { result, counter };
}

// zadanie 8

function prefix(arr) {

    let start = arr[0];

    for (let txt of arr) {
        while (txt.indexOf(start) !== 0) {
            start = start.substring(0, start.length - 1);
            if(start === "") return ""
        }
    }

    return start;
}

// zadanie 9

function romanToInteger(txt) {
    const map = new Map();

    map.set("I", 1);
    map.set("V", 5);
    map.set("X", 10);
    map.set("L", 50);
    map.set("C", 100);
    map.set("D", 500);
    map.set("M", 1000);

    let result = 0;
    let prev = 0;

    for(let i of txt.split("")) {
        let current = map.get(i);
        if(current > prev) {
            result += current - 2 * prev;
        } else {
            result += current;
        }
        prev = current;
    }

    return result;
}

let s1 = "III";
let s2 = "LVIII";
let s3 = "MCMXCIV";

console.log(romanToInteger(s3));


// zadanie 11
function getLastLength(txt) {
    let arr = txt.trim().split(" ");
    return arr[arr.length - 1].length
}

console.log(getLastLength("Ala ma kota "))

// zadanie 12
function howManyOptions(n) {

    if (n <= 1) return 1; 

    let prev1 = 1;
    let prev2 = 1;

    for(let i = 2 ; i <= n ; i++) {
        let current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

console.log(howManyOptions(45)); 

