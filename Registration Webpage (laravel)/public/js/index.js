// Add a global variable to track WhatsApp validation status
let isWhatsAppValid = 2;

document.addEventListener("DOMContentLoaded", function() {
    document.getElementById("validateWhatsApp").addEventListener("click", function() {
        var countryCode = document.getElementById("countryCode").value;
        var whatsappNumber = document.getElementById("whatsAppNumber").value.trim();

        if (whatsappNumber === "") {
            document.getElementById("whatsappValidationResult").innerText = "Please enter a WhatsApp number.";
            isWhatsAppValid = false;
            return;
        }

        var fullNumber = countryCode + whatsappNumber;

        var xhr = new XMLHttpRequest();
        xhr.open("POST", "API_Ops.php", true);
        xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");

        xhr.onreadystatechange = function() {
            if (xhr.readyState === 4) {
                if (xhr.status === 200) {
                    document.getElementById("whatsappValidationResult").innerHTML = xhr.responseText;
                    // Check if response indicates a valid number
                    if (xhr.responseText.includes("Valid WhatsApp number")) {
                        isWhatsAppValid = 1;
                    } else {
                        isWhatsAppValid = 0;
                    }
                } else {
                    document.getElementById("whatsappValidationResult").innerText = "Server error: " + xhr.status;
                    isWhatsAppValid = 0;
                }
            }
        };

        xhr.send("whatsAppNumber=" + encodeURIComponent(fullNumber));
    });
});

document.getElementById("registrationForm").addEventListener("submit", function(event) {
    if (!validateForm()) {
        event.preventDefault(); // Prevent form submission
    }
});

function checkUsername() {
    var username = document.getElementById("username").value;

    if (username.length < 3) {
        document.getElementById("username-status").innerHTML = "<span style='color:red;'>Username too short</span>";
        return;
    }

    var xhr = new XMLHttpRequest();
    xhr.open("POST", "check_username.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");

    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4 && xhr.status == 200) {
            document.getElementById("username-status").innerHTML = xhr.responseText;
        }
    };

    xhr.send("username=" + encodeURIComponent(username));
}

function validateForm() {
    let fullName = document.getElementById("fullName").value.trim();
    let username = document.getElementById("username").value;
    let user_status = document.getElementById("username-status").innerHTML;
    let email = document.getElementById("email").value.trim();
    let password = document.getElementById("password").value;
    let confirmPassword = document.getElementById("confirmPassword").value;
    let phone = document.getElementById("phone").value;
    let whatsapp = document.getElementById("whatsAppNumber").value;

    // Full Name Validation
    if (!/^[A-Za-z\s]+$/.test(fullName)) {
        alert("Full Name must contain only letters and spaces!");
        return false;
    }

    // Username Validation
    if (username.length < 3) {
        alert("Username must be at least 3 characters long!");
        return false;
    }
    if (user_status.includes("Username already taken")) {
        alert("This username is already taken. Please choose another one.");
        return false;
    }

    // Email Validation
    if (!/^\S+@\S+\.\S+$/.test(email)) {
        alert("Enter a valid email address!");
        return false;
    }

    // Password Validation
    if (!/(?=.*\d)(?=.*[!@#$%^&*]).{8,}/.test(password)) {
        alert("Password must be at least 8 characters long, contain at least 1 number, and 1 special character.");
        return false;
    }

    // Phone Validation
    if (!/^\d{11}$/.test(phone)) {
        alert("Phone number must be 11 digits!");
        return false;
    }

    // WhatsApp Number Validation
    if (!/^\d{10}$/.test(whatsapp)) {
        alert("Enter a valid 10-digit WhatsApp number!");
        return false;
    } 
    if (isWhatsAppValid == 2) { // If the user didn't click the validate button from first
        alert("Please click the validate Whatsapp Number button first before submitting!");
        return false;
    }
    else if (isWhatsAppValid == 0) { // if the Whatsapp Number is invalid
        alert("Please enter a valid Whatsapp Number!");
        return false;
    }

    // Confirm Password Validation
    if (password !== confirmPassword) {
        alert("Passwords do not match!");
        return false;
    }

    return true; // Allow form submission
}