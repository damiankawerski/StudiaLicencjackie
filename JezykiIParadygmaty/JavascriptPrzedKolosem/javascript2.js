// zadanie 1
const currentUser = {
    name: "Damian",
    surname: "Kawerski",
    email: "damian.kawerski@gmail.com",
    www: "Costam.www",
    userType: "Admin",
    isActive: true,

    show: function() {
        console.log(this.name + this.surname);
    }
}

// currentUser.show();

// zadanie 2

class Book {
    users = [];
    
    addUser(name, age, phone) {
        this.users.push({name, age, phone});
    }

    showUsers() {
        for(let user of this.users) {
            console.log(user);
        }
    }

    findByName(name) {
        for(let user of this.users) {
            if(user.name === name) {
                console.log(user);
                return true;
            }
        }
        return false;
    }

}

// let book = new Book();
// book.addUser("damian", 20, 506);
// book.showUsers();
// book.findByName("damian");


const text = {
    check(txt, word) {
        return txt.includes(word);
    },

    getCount(txt) {
        return txt.split("").length;
    },

    getWordsCount(txt) {
        return txt.trim().split(" ").length;
    },

    setCapitalize(txt) {
        let result = "";
        for(let word of txt.trim().split(" ")) {
            result += word[0].toUpperCase() + word.slice(1) + " ";
        }
        return result.trim();
    },

    setMix(txt) {
        let result = "";
        let arr = txt.trim().split("");
        for (let i = 0 ; i < arr.length ; i++) {
            if(i % 2 == 0) {
                result += arr[i].toLowerCase();
            } else {
                result += arr[i].toUpperCase();
            }
        }
        return result;
    },

    generateRandom(lng) {
        let min = 97;
        let max = 122;
        let result = "";
        for(let i = 0 ; i < lng ; i++) {
            result += String.fromCharCode(Math.floor(Math.random() * (max - min + 1) + min));
        }
        return result;
    }
}


let txt = "Ala ma kota";
// console.log(text.check(txt, "Aa"));
// console.log(text.getCount(txt));
// console.log(text.getWordsCount(txt));
// console.log(text.setCapitalize(txt));
// console.log(text.setMix(txt));
// console.log(text.generateRandom(10));


// zadanie 4
String.prototype.mirror = function() {
    return this.trim().split("").reverse().join("");
}


console.log(txt.mirror());


// zadanie 5
function createCounter() {
    let count = 0;

    return function() {
        count++;
        return count;
    }
}

const counter1 = createCounter();
console.log(counter1()); // 1
console.log(counter1()); // 2
console.log(counter1()); // 3

const counter2 = createCounter();
console.log(counter2()); // 1
console.log(counter2()); // 2