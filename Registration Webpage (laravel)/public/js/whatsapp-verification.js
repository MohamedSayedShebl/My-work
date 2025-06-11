document.addEventListener('DOMContentLoaded', function() {
    const validateButton = document.getElementById('validateWhatsApp');
    const whatsappInput = document.getElementById('whatsAppNumber');
    const countryCode = document.getElementById('countryCode');
    const validationResult = document.getElementById('whatsappValidationResult');

    validateButton.addEventListener('click', function() {
        const fullNumber = '+' + countryCode.value + whatsappInput.value;

        // Show loading state
        validationResult.innerHTML = 'Validating...';
        validationResult.style.color = 'blue';

        // Make the API request
        fetch('/verify-whatsapp', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
                'X-CSRF-TOKEN': document.querySelector('meta[name="csrf-token"]').content
            },
            body: JSON.stringify({
                whatsAppNumber: fullNumber
            })
        })
        .then(response => response.json())
        .then(data => {
            if (data.status === 'success') {
                validationResult.innerHTML = data.message;
                validationResult.style.color = 'green';
            } else {
                validationResult.innerHTML = data.message;
                validationResult.style.color = 'red';
            }
        })
        .catch(error => {
            validationResult.innerHTML = 'Error validating number. Please try again.';
            validationResult.style.color = 'red';
            console.error('Error:', error);
        });
    });
});
