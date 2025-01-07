const searchMeal = () => {
    const mealName = document.getElementById("meal-search").value;
    if (mealName) {
        fetch(`https://www.themealdb.com/api/json/v1/1/search.php?s=${mealName}`)
            .then(response => response.json())
            .then(data => {
                if (data.meals) {
                    displayMeals(data.meals);
                } else {
                    document.getElementById('meal-container').innerHTML = '<p class="no-meal">No meal found</p>';
                    document.getElementById('meal-details').innerHTML = '';
                }
            })
            .catch(error => console.error("Error fetching meal data:", error));
    }
};

const displayMeals = (meals) => {
    const mealContainer = document.getElementById("meal-container");
    mealContainer.innerHTML = '';

    meals.forEach(meal => {
        const div = document.createElement("div");
        div.classList.add("card");
        div.innerHTML = `
            <img src="${meal.strMealThumb}" alt="${meal.strMeal}">
            <h4>${meal.strMeal}</h4>
            <button onclick="showMealDetails('${meal.idMeal}')">Show Details</button>
        `;
        mealContainer.appendChild(div);
    });
};

const showMealDetails = (mealId) => {
    fetch(`https://www.themealdb.com/api/json/v1/1/lookup.php?i=${mealId}`)
        .then(response => response.json())
        .then(data => {
            const meal = data.meals[0];
            const mealDetails = document.getElementById("meal-details");
            mealDetails.innerHTML = `
                <h2>${meal.strMeal}</h2>
                <img src="${meal.strMealThumb}" alt="${meal.strMeal}">
                <p><strong>Category:</strong> ${meal.strCategory}</p>
                <p><strong>Area:</strong> ${meal.strArea}</p>
                <p><strong>Instructions:</strong> ${meal.strInstructions}</p>
            `;
        })
        .catch(error => console.error("Error fetching meal details:", error));
};
