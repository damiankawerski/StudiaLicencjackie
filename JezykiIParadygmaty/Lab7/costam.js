function checkPalindrom(txt) {
    return txt.split('').reverse().join('') === txt;
}

console.log(checkPalindrom(`ala`));