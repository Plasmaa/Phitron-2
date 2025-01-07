// const target = document.getElementById("h1");

// target.style.color = "red";

// const allbox = document.getElementsByClassName("box");

// console.log(allbox);

// for (let i = 0; i < allbox.length; i++) {
//     const element = allbox[i];
//     element.style.backgroundColor = "lightblue";

//     if (element.innerText == "box-5") {
//         element.style.backgroundColor = "purple";
//     }
// }

document.getElementById("search-box").addEventListener("keyup", (event) => {
    if (event.key === "Enter") {
        const inputValue = document.getElementById("search-box").value;

        const container = document.getElementById("comment-container");

        const p = document.createElement("p");
        p.classList.add("child");
        p.innerText = inputValue;
        container.appendChild(p);

        document.getElementById("search-box").value = ""; // for clearing the input field

        const allComments = document.getElementsByClassName("child");

        for (const element of allComments) {
            if (!element.querySelector(".cross")) {
                const cross = document.createElement("button");
                cross.classList.add("cross");
                cross.innerText = "X";
                const span = document.createElement("span");
                span.style.margin = "0 5px";
                element.appendChild(span);
                element.appendChild(cross);

                cross.addEventListener("click", (e) => {
                    element.remove();
                });
            }
        }

        for (const element of allComments) {
            element.addEventListener("click", (e) => {
                e.target.parentNode.removeChild(element);
            })
        }
    }
});

// const haddleSearch = (event) => {
//     const inputValue = document.getElementById("search-box").value;
//     console.log(inputValue);
// }

// using api
fetch("https://jsonplaceholder.typicode.com/posts")
    .then(res => res.json())
    .then(data => {
        console.log(data);
        displayData(data);
    })
    .catch(err => {
        console.log(err)
    });


const displayData = (userData) => {
    const container = document.getElementById("userData-container");

    userData.forEach(user => {
        const div = document.createElement("div");
        div.classList.add("user");
        div.innerHTML = `
        <h4>Title</h4>
        <p>Description</p> 
        <button>Details</button>

        `
        container.appendChild(div);
    });

}
