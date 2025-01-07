const largestName = (names) => {
    let biggestName = names[0];

    for (let i = 0; i < names.length; i++) {
        const element = names[i];
        if (element.length > biggestName.length) {
            biggestName = element;
        }
    }
    return biggestName;
}

const Names = ["rahim", "karim", "abdul", "sadsd", "heroAlom"];
const result7 = largestName(Names);
console.log(result7);


