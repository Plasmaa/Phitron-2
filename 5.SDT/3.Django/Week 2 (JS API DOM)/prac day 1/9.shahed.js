let payments = [3000, 2000, 2500, 4000, 3200, 1800, 5000, 2700, 3500, 4100, 2900, 4500];
let livingCost = 1500;
const monthlySavings = () => {
    let totalPayment = 0;
    for (let i = 0; i < payments.length; i++) {
        const element = payments[i];
        if (element >= 3000) {
            totalPayment += element * 0.8;
        } else {
            totalPayment += element;
        }
    }
    const savings = totalPayment - livingCost * 12;
    if (savings < 0) {
        console.log("Earn more");
    } else {
        console.log("Savings:", savings);
    }
}
monthlySavings();

