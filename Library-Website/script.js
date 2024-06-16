  const banButtons = document.querySelectorAll('button[value="Ban"]');
  banButtons.forEach(function(button) {
    button.addEventListener('click', function() {
      alert(`User banned successfully!`);
    });
  });

