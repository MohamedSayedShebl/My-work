    function checkUsername() {
        const username = document.getElementById("username").value;
        const status = document.getElementById("username-status");

    if (username.length < 3) {
        status.textContent = "Username too short.";
        status.style.color = "red";
        return;
    }

    fetch(`/check-username?username=${encodeURIComponent(username)}`)
        .then(response => response.json())
        .then(data => {
            if (data.exists) {
                status.textContent = "Username already taken.";
                status.style.color = "red";
            } else {
                status.textContent = "Username available!";
                status.style.color = "green";
            }
    })
    .catch(() => {
        status.textContent = "Error checking username.";
        status.style.color = "orange";
    });
    }

    document.getElementById("registrationForm").addEventListener("submit", function(event) {
        const password = document.getElementById("password").value;
        const confirmPassword = document.getElementById("password_confirmation").value;
        const passwordPattern = /^(?=.*[0-9])(?=.*[!@#$%^&*])[A-Za-z\d!@#$%^&*]{8,}$/;

        if (!passwordPattern.test(password)) {
            alert("Password must be at least 8 characters long, include at least one number and one special character.");
            event.preventDefault();
            return;
        }

        if (password !== confirmPassword) {
            alert("Passwords do not match.");
            event.preventDefault();
        }
    });