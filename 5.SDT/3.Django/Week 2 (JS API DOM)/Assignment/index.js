const API_URL = 'https://www.thecocktaildb.com/api/json/v1/1';

let selectedDrinks = [];

const loadDrinks = () => {
    fetch(`${API_URL}/search.php?f=a`)
        .then(response => response.json())
        .then(data => displayDrinks(data.drinks))
        .catch(error => console.error("Error loading drinks:", error));
};

const displayDrinks = (drinks) => {
    const container = document.getElementById('drink-container');
    container.innerHTML = '';
    drinks.forEach(drink => {
        const card = document.createElement('div');
        card.className = 'card';
        card.innerHTML = `
            <img src="${drink.strDrinkThumb}" alt="${drink.strDrink}">
            <h3>${drink.strDrink}</h3>
            <p>Category: ${drink.strCategory}</p>
            <p>Instructions: ${drink.strInstructions.slice(0, 15)}...</p>
            <div class="btn-container">
                <button id="add-btn-${drink.idDrink}" onclick="addToCart(${drink.idDrink}, '${drink.strDrink}', '${drink.strDrinkThumb}')">Add Drinks</button>
                <button onclick="showDetails(${drink.idDrink})">Details</button>
            </div>
        `;
        container.appendChild(card);
    });
};

const addToCart = (id, name, image) => {
    if (selectedDrinks.length >= 7) {
        alert("You cannot add more than 7 drinks to the group.");
        return;
    }
    selectedDrinks.push({ id, name, image });
    updateSelectedDrinks();
    const addButton = document.getElementById(`add-btn-${id}`);
    addButton.classList.add('added');
    addButton.disabled = true;
    addButton.textContent = 'Already Added';
};

const updateSelectedDrinks = () => {
    const drinkList = document.getElementById('drink-list');
    const drinkCount = document.getElementById('drink-count');

    drinkList.innerHTML = '';

    selectedDrinks.forEach((drink, index) => {
        const listItem = document.createElement('li');
        listItem.innerHTML = `
            <span>${index + 1}. </span>
            <img src="${drink.image}" alt="${drink.name}" width="50">
            <span>${drink.name}</span>
        `;
        drinkList.appendChild(listItem);
    });

    drinkCount.innerText = selectedDrinks.length;
};

const searchCocktails = () => {
    const query = document.getElementById('search-input').value;
    fetch(`${API_URL}/search.php?s=${query}`)
        .then(response => response.json())
        .then(data => {
            if (data.drinks) {
                displayDrinks(data.drinks);
            } else {
                document.getElementById('drink-container').innerHTML = '<p>No drinks found.</p>';
            }
        })
        .catch(error => console.error("Error searching drinks:", error));
};

const showDetails = (id) => {
    fetch(`${API_URL}/lookup.php?i=${id}`)
        .then(response => response.json())
        .then(data => {
            const drink = data.drinks[0];
            document.getElementById('modal-image').src = drink.strDrinkThumb;
            document.getElementById('modal-name').innerText = drink.strDrink;
            document.getElementById('modal-category').innerText = `Category: ${drink.strCategory}`;
            document.getElementById('modal-instructions').innerText = `Instructions: ${drink.strInstructions}`;
            document.getElementById('modal-ingredients').innerHTML = '';
            for (let i = 1; i <= 15; i++) {
                const ingredient = drink[`strIngredient${i}`];
                const measure = drink[`strMeasure${i}`];
                if (ingredient) {
                    const li = document.createElement('li');
                    li.innerText = `${measure || ''} ${ingredient}`;
                    document.getElementById('modal-ingredients').appendChild(li);
                }
            }
            $('#drinkModal').modal('show');
        })
        .catch(error => console.error("Error loading drink details:", error));
};

loadDrinks();


