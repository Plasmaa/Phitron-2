// ---------------------- basics of js ------------------
console.log("------------------ basics ------------------");
var test = 10;
var result = test * 2;
console.log(result);

var test2 = 'hello';
var result2 = test2 + ' world';
console.log(result2);

console.log(typeof result2);
var status = false;
console.log(typeof status);

// ------------------------ parseFloat and parseInt -------------------
console.log("------------------ parseFloat and parseInt ------------------");
var num1 = '10.5';
var num2 = 20;
var result3 = parseFloat(num1) + num2;
console.log(result3);
var result4 = parseInt(num1) + num2;
console.log(result4);
console.log(typeof result4);



//--------------- if, else if, else ----------------------------
console.log("------------------ if, else if, else ------------------");
var age = 18;
if (age >= 18) {
    console.log('You can vote');
} else {
    console.log('You cannot vote');
}
var status2 = "rain";
if (status2 == "rain") {
    console.log('Take an umbrella');
} else if (status2 == 'snow') {
    console.log('Take a coat');
} else {
    console.log('Go outside');
}


// ----------------- switch case ----------------------------
console.log("------------------ switch case ------------------");
var status3 = "rain";
switch (status3) {
    case "rain":
        console.log('Take an umbrella');
        break;
    case 'snow':
        console.log('Take a coat');
        break;
    default:
        console.log('Go outside');
        break;
}


// ----------------- Object ----------------------------

console.log("---------------------Object----------------");
var person = {
    name: 'Asad',
    age: 20,
    address: 'Dhaka',
    hair: 'curly',
    friends: ['Rahim', 'Karim', 'Fahim'],
    father: {
        name: 'Mamun',
        age: 50
    },
}
console.log(person);
console.log(person.friends[1]);
console.log(person.father.name);
console.log("Father's name : " + person.father.name + " Fathers age : " + person.father.age);


// ----------------------- Array ----------------------------
console.log("---------------------Array----------------");
var friends = ['Rahim', 'Karim', 'Fahim'];
console.log(friends[1]);
friends.push('Asad');
console.log(friends);
friends.pop();
console.log(friends);
friends.unshift('Asad');  // adding in front
console.log(friends);
friends.shift();  // removing from front
console.log(friends);

var multiple_types = ['Rahim', 'Karim', 'Fahim', 10, 20, 30, { name: 'Asad', age: 20 }];
console.log(multiple_types);
console.log(multiple_types[2]);
console.log(multiple_types.length);

var marks = [10, 20, 30, 40, 50];
console.log(marks);
console.log("marks are : ");
console.log(marks[3]);

// ----------------- Function ----------------------------
console.log(" --------------------- Function -------------------- ");
function add(num1, num2) {
    var result = num1 + num2;
    return result;
}
var sum = add(10, 20);
console.log(sum);


// --------------------- loops ----------------------------
console.log(" --------------------- loops ------------------------ ");
var friends = ['Rahim', 'Karim', 'Fahim'];  // array
for (var i = 0; i < friends.length; i++) {
    var friend = friends[i];
    console.log(friend);
}
for (var i = 0; i < friends.length; i++) {
    console.log(i + " : " + friends[i]);
}
// forEach
var friends = ['Rahim', 'Karim', 'Fahim'];  // array
friends.forEach(function (friend) {
    console.log(friend);
});
// while
var friends = ['Rahim', 'Karim', 'Fahim'];  // array
var i = 0;
while (i < friends.length) {
    var friend = friends[i];
    console.log(friend);
    i++;
}
// do while
var friends = ['Rahim', 'Karim', 'Fahim'];  // array
var i = 0;
do {
    var friend = friends[i];
    console.log(friend);
    i++;
} while (i < friends.length);


// --------------------- String ----------------------------
console.log("---------------------String------------------------ ");
var name = 'Asad';
console.log(name);  // Asad
console.log(name.length);  // 4
console.log(name.toUpperCase());  // ASAD
console.log(name.toLowerCase());  // asad
console.log(name.indexOf('a'));  // 1
console.log(name.slice(0, 3));  // Asa
console.log(name.replace('a', 'A'));  // AsAd

var name = 'Asad';
var age = 20;
var info = 'My name is ' + name + ' and I am ' + age + ' years old';
console.log(info);


// --------------------- Date ----------------------------
console.log("---------------------Date------------------------ ");
var date = new Date();
console.log("Date: " + date);
console.log("Year: " + date.getFullYear());
console.log("Month: " + date.getMonth());
console.log("Date: " + date.getDate());
console.log("Day: " + date.getDay());
console.log("Hours: " + date.getHours());
console.log("Minutes: " + date.getMinutes());
console.log("Seconds: " + date.getSeconds());
console.log("Time: " + date.getTime()); // in milliseconds


// --------------------- Math ----------------------------
var title = " --------------------- Math ------------------------ ";
console.log(title);
var num1 = 10;
var num2 = 20;
var result = num1 + num2;
console.log(result);
console.log(Math.max(num1, num2));
console.log(Math.min(num1, num2));
console.log(Math.random());
// generate random number between 1-100
console.log(Math.floor(Math.random() * 100) + 1);
console.log(Math.floor(Math.random() * 10) + 1);


