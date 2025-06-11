<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Footer Example</title>

    <!-- You NEED Font Awesome for the icons -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.2/css/all.min.css">

    <!-- Optional: Include Poppins font if not already loaded globally -->
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@400;600;700&display=swap" rel="stylesheet">

    <style>
        /* Basic body styling for context (you might have this elsewhere) */
        body {
            font-family: 'Poppins', sans-serif;
            margin: 0;
            padding: 0;
            /* Example background to see footer contrast */

            /* For sticky footer demo if needed: */
            /* display: flex; */
            /* flex-direction: column; */
            /* min-height: 100vh; */
        }

        /* Optional: Main content grows to push footer down */
        /* main { flex-grow: 1; } */


        /* --- Keyframes for Gradient Animation (Required for Footer) --- */
        @keyframes gradientShift {
            0% {
                background-position: 0% 50%;
            }

            50% {
                background-position: 100% 50%;
            }

            100% {
                background-position: 0% 50%;
            }
        }

        /* --- Funky Beige Footer Styles --- */

        footer {
            /* Use the beige/brown gradient */
            background: linear-gradient(135deg, #D2B48C 5%, #A0522D 50%, #8B4513 95%);
            /* Tan -> Sienna -> SaddleBrown */
            /* Apply the animation */
            background-size: 200% 200%;
            animation: gradientShift 18s ease infinite;

            color: #FFF8DC;
            /* Cornsilk text */
            text-align: center;
            padding: 20px 30px;
            /* Padding */
            margin-top: 40px;
            /* Adjust spacing as needed, or use flexbox on body */
            /* Inverted shadow matching header */
            box-shadow: 0 -8px 16px rgba(78, 52, 46, 0.25), 0 -4px 6px rgba(78, 52, 46, 0.15);
            /* Rounded top corners */
            border-radius: 25px 25px 0 0;
            /* Top border matching text/accent color */
            border-top: 3px solid rgba(255, 248, 220, 0.6);
            /* Semi-transparent Cornsilk */
            position: relative;
            overflow: hidden;
            /* Hide gradient overflow */
        }

        .footer-content {
            display: flex;
            justify-content: center;
            align-items: center;
            /* Align items vertically */
            flex-wrap: wrap;
            /* Allow wrapping on smaller screens */
            gap: 30px;
            /* Space between links */
            margin-bottom: 15px;
            /* Space above copyright */
        }

        .footer-content a {
            color: #FFF8DC;
            /* Cornsilk text */
            text-decoration: none;
            font-size: 0.95em;
            font-weight: 600;
            padding: 5px 10px;
            /* Padding around link */
            border-radius: 15px;
            /* Slightly rounded corners */
            transition: all 0.3s ease;
            /* Smooth transition */
            display: inline-flex;
            /* Align icon and text */
            align-items: center;
            gap: 8px;
            /* Space between icon and text */
            text-shadow: 1px 1px 2px rgba(78, 52, 46, 0.5);
            /* Dark text shadow for readability */
        }

        .footer-content a i {
            transition: transform 0.3s ease;
            /* Transition for icon hover effect */
        }

        .footer-content a:hover {
            color: #FFFFFF;
            /* Brighter white on hover */
            background-color: rgba(255, 248, 220, 0.15);
            /* Subtle background highlight */
            transform: translateY(-2px);
            /* Slight lift effect */
        }

        .footer-content a:hover i {
            transform: scale(1.15);
            /* Make icon slightly bigger on hover */
        }

        /* Style the copyright paragraph */
        footer p {
            margin: 0;
            /* Remove default margin */
            font-size: 0.85em;
            /* Smaller text */
            color: rgba(255, 248, 220, 0.8);
            /* Slightly transparent Cornsilk */
        }
    </style>

</head>

<body>

    <footer>
        <div class="footer-content">
            <a href="#"><i class="fas fa-phone"></i> @lang('messages.contact_us')</a>
            <a href="#"><i class="fas fa-shield-alt"></i> @lang('messages.privacy_policy')</a>
            <a href="#"><i class="fas fa-gavel"></i> @lang('messages.terms_of_service')</a>
        </div>
        <p>© <?php echo date("Y"); ?> @lang('messages.copyright')</p> <!-- Use PHP for dynamic year -->
    </footer>

</body>

</html>
