

// Define valid usernames and passwords
const credentials = {
  "mina": "mina12",
  
};

function authenticate() {
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

function sendRequest(url) {
  var xhr = new XMLHttpRequest();
  xhr.open("GET", url, true);
  xhr.send();
}


//////////////////////////////////////////
const initPinScreen = (selector, onEnter) => {
	const container = document.querySelector(selector);
	const input = container.querySelector(".pin-value");
	const keys = container.querySelectorAll(".pin-keyboard-key");

	const clear = () => {
		input.value = "";
	};

	for (const key of keys) {
		key.addEventListener("click", () => {
			const value = key.textContent.trim();

			if (key.classList.contains("pin-keyboard-key--clear")) {
				clear();
			} else if (key.classList.contains("pin-keyboard-key--enter")) {
				input.value && onEnter && onEnter(input.value, clear);
			} else {
				input.value += value;
			}
		});
	}
};

let attempts = 0;

initPinScreen("#mainPinScreen", (pin, clear) => {
  const correct_pin = 1234;

	console.log(`Entered Pin: ${pin}`);
  if (correct_pin == pin){
    
    document.getElementById("control-panel").style.display = "block";
    document.getElementById("auth-panel").style.display = "none";
    document.getElementById("lock-panel").style.display = "none";
    sendRequest('http://192.168.243.126/O');//send open door
  }
 else {
  attempts++; // Increment attempt counter
  if (attempts < 3 ) {
    alert(`Invalid PIN. You have ${3 - attempts} attempt(s) left.`);
    sendRequest('http://192.168.243.126/W');// send siren
  } else {
    alert("You have been locked out due to too many incorrect attempts.");
    // document.getElementById("auth-panel").style.display = "none";
    // document.getElementById("lock-panel").style.display = "block";
    sendRequest('http://192.168.243.126/S');// send siren
  }
}
	clear();
});

function displayLock() {
  document.getElementById("control-panel").style.display = "none";
    document.getElementById("auth-panel").style.display = "none";
    document.getElementById("lock-panel").style.display = "flex";
}

function toggleLights(){
  const img = document.getElementById("lightsImg");
  const currentSrc = img.src;
  let newSrc;
  if (currentSrc.includes("assets/lightOff.svg")) {
      newSrc = "assets/lightOn.svg"; // Change to light on
      sendRequest('http://192.168.243.126/H');
  } else {
      newSrc = "assets/lightOff.svg"; // Change to light off
      sendRequest('http://192.168.243.126/L');
  }


  img.src = newSrc; // Change the image source
};
