let array = [8, 5, 14, 1, 17, 20, 3, 12, 6, 9, 15, 11, 10, 4, 16, 7, 18, 2, 13, 19];
// Bubble sort
for (let i = 0; i < array.length - 1; i++) {
    for (let j = 0; j < array.length - 1 - i; j++) {
        if (array[j] > array[j + 1]) {
            [array[j], array[j + 1]] = [array[j + 1], array[j]];
        }
    }
}
console.log("Sorted array (Bubble Sort):", array);


