// zadanie 9

function romanToInteger(s) {
    const romanNumerals = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    };

    let sum = 0;
    

    for (let i = 0; i < s.length; i++) {
        current = romanNumerals[s[i]];
        next = romanNumerals[s[i + 1]];

        if (next > current) {
            sum += next - current;
        } else {
            sum += current;
        }
    }

    return sum;
}

// Tests

console.log(romanToInteger("III")); // 3
console.log(romanToInteger("IV")); // 4
console.log(romanToInteger("IX")); // 9
console.log(romanToInteger("LVIII")); // 58

// zadanie 10

function labirynth() {
    const arr = [
        [ 66,  97, 114, 100,   4,   2, 110,  11,   1,   6,  20, ],
        [ 99,   3,  10, 122,  76, 101, 111,   3,  32, 100,   0, ],
        [  6,  22,   1, 111,  32,  10, 110,   7,  97,  97,  67, ],
        [ 60,  97, 116,  32, 100,  23,  97, 114, 100,  32,  34, ],
        [  2, 106,  15,   6, 111,  56,  80,  20,  10,  86,  10, ],
        [ 20, 110,  121, 32, 107,  55,  50,  99, 110, 105,   8, ],
        [ 12,   9,  22, 102,  66, 100,  12, 105,  50,  76, 110, ],
        [ 42,  81, 123,  92,  26,  98,  20,   1,  20,  11,  10, ],
    ]

    const str = "rrrdddllddrrruuuurrddrruurddddlld";

    results = [];

    j = 0;
    i = 0;

    for (let k = 0 ; k < str.length ; k++) {
        results.push(String.fromCharCode(arr[i][j]));
        if (str[k] == "u") {
            i--;
        } else if (str[k] == "d") {
            i++;
        } else if (str[k] == "l") {
            j--;
        } else if (str[k] == "r") {
            j++;
        }
    }
    return results;
}

console.log(labirynth().join("")); 

// zadanie 11
function lastWordLength(s) {
    const words = s.trim().split(" ");
    return words[words.length - 1].length;
}

s = "Hello World";
console.log(lastWordLength(s)); // 5

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