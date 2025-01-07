// -------------- let and const ------------
console.log(" --------------------- let and const ------------------------ ");
const num = 1;

let name = "Zarif";
name = "gg";

console.log(num);
console.log(name);

// tamplet literals & Spread Operators 
console.log(" --------------------- tamplate literals & spread operators ------------------------ ");

const CountryName = "Bangladesh";
const country = `I am from ${CountryName}`;
console.log(country);

const numbers = [1, 2, 3, 4, 5];
const newNumbers = [...numbers, 6, 7, 8];
console.log(newNumbers);


// --------------------- Distructuring ----------------------------
console.log(" --------------------- Distructuring Array & Object ------------------------ ");

const person = {
    name2: 'Asad',
    age: 20,
    friends: ['Rahim', 'Karim', 'Fahim'],
}
const { name2, age, friends } = person;
console.log(name2, age, friends);

// --------------------- Arrow Function ----------------------------
console.log(" --------------------- Arrow Function ------------------------ ");
const add = (num1, num2) => num1 + num2;
const result = add(10, 20);
console.log(result);


// --------------------- Find ----------------------------
console.log(" --------------------- Find ------------------------ ");
const friends2 = ['Rahim', 'Karim', 'Fahim'];
const friend = friends.find(f => f === 'Rahim');
console.log(friend);


const products = [
    { id: 1, name: 'Laptop', price: 10000, description: 'A portable personal computer', color: 'black' },
    { id: 2, name: 'Mobile', price: 20000, description: 'A portable phone', color: 'white' },
    { id: 3, name: 'Watch', price: 30000, description: 'A portable time keeping device', color: 'black' },
    { id: 4, name: 'Keyboard', price: 40000, description: 'An input device for typing', color: 'black' },
    { id: 5, name: 'Mouse', price: 50000, description: 'An input device for navigation', color: 'black' },
];

const result3 = products.find(pd => pd.id === 3);
console.log(result3);


// --------------------- Filter ----------------------------
console.log(" --------------------- Filter ------------------------ ");
const result4 = products.filter(pd => pd.color === 'black'); // for multiple value finding 
console.log(result4);


// --------------------- Map ----------------------------
console.log(" --------------------- Map ------------------------ ");
const result5 = products.map(pd => pd.price);
console.log(result5);

// --------------------- ForEach ----------------------------
console.log(" --------------------- ForEach ------------------------ ");
products.forEach(pd => console.log(pd.name));


// --------------------- problem 1 (odd and even) ----------------------------
console.log(" --------------------- problem 1 (odd and even) ------------------------ ");
const number2 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20];
const oddEven = (array) => {
    const odd = [];
    const even = [];
    for (let i = 0; i < array.length; i++) {
        const element = array[i];
        if (element % 2 === 0) {
            even.push(element);
        }
        else {
            odd.push(element);
        }
    }
    return [odd, even];
}

const result6 = oddEven(number2);
console.log(result6);


// --------------------- problem 2 (Longest Name) ----------------------------
console.log(" --------------------- problem 2 (Longest Name) ------------------------ ");

const checkShohid = (array) => {
    let biggestName = array[0];

    for (let i = 0; i < array.length; i++) {
        const element = array[i];
        if (element.length > biggestName.length) {
            biggestName = element;
        }
    }
    return biggestName;
}

const Shohids = ['salam', 'borkot', 'rofiq', 'jobbar', 'bangladesh', 'ggez'];
const result7 = checkShohid(Shohids);
console.log(result7);


alert("Error");