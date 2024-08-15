const credentials={
    "mina":"mina",
    "Raafat":"Raafat123"
};

function auth(){
    const username = document.getElementById("username").value;
    const password = document.getElementById("password").value;
    if (credentials[username] && credentials[username] === password) {
        // Show control panel if authentication is successful
        document.getElementById("control-panel").style.display = "block";
        document.getElementById("auth-panel").style.display = "none";

      } else {
        alert("Invalid username or password. Please try again.");
      }
    
}
