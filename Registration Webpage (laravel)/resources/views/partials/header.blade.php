<?php // Header.php ?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registration Page - Funky Beige!</title>

    <!-- Google Font (Poppins) -->
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@400;600;700&display=swap" rel="stylesheet">

    <!-- Font Awesome -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.2/css/all.min.css">

    <style>
        body {
            font-family: 'Poppins', sans-serif;
            /* Warm, soft beige background */
            /* Linen */
            /* Or try a subtle radial gradient with beige tones */
            /* background: radial-gradient(circle, #FFF8DC 0%, #FAEBD7 100%); */
            /* Cornsilk to AntiqueWhite */
            margin: 0;
            padding: 0;
            color: #5D4037;
            /* Darker brown for body text */
        }

        header {
            /* Funky Beige/Brown Gradient - Think retro wood paneling or coffee tones */
            background: linear-gradient(135deg, #D2B48C 5%, #A0522D 50%, #8B4513 95%);
            /* Tan -> Sienna -> SaddleBrown */
            /* Keep the animation */
            background-size: 200% 200%;
            animation: gradientShift 18s ease infinite;
            /* Slightly slower animation */

            color: #FFF8DC;
            /* Cornsilk - off-white text works well on brown */
            padding: 15px 30px;
            display: flex;
            justify-content: space-between;
            align-items: center;
            /* Softer shadow, perhaps slightly brown-tinted */
            box-shadow: 0 8px 16px rgba(78, 52, 46, 0.25), 0 4px 6px rgba(78, 52, 46, 0.15);
            border-radius: 0 0 25px 25px;
            position: relative;
            overflow: hidden;
            /* Border matching the text color */
            border-bottom: 3px solid rgba(255, 248, 220, 0.6);
            /* Semi-transparent Cornsilk */
        }

        /* Keyframes for the gradient animation (same logic, different colors implicitly) */
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

        .nav-container {
            display: flex;
            align-items: center;
            width: 100%;
            justify-content: space-between;
        }

        .logo-container {
            display: flex;
            align-items: center;
        }

        .logo {
            height: 65px;
            width: auto;
            margin-right: 15px;
            border-radius: 50%;
            /* Keep it round if appropriate */
            /* Border matching the text color */
            border: 3px solid #FFF8DC;
            /* Cornsilk */
            /* Light shadow matching border */
            box-shadow: 0 0 10px rgba(255, 248, 220, 0.7);
            transition: transform 0.4s cubic-bezier(0.68, -0.55, 0.27, 1.55), box-shadow 0.3s ease;
        }

        .logo:hover {
            transform: scale(1.1) rotate(-10deg);
            /* Brighter shadow on hover */
            box-shadow: 0 0 20px rgba(255, 248, 220, 1);
        }


        nav ul {
            list-style: none;
            padding: 0;
            margin: 0;
            display: flex;
            gap: 10px;
        }

        nav ul li a {
            color: #FFF8DC;
            /* Cornsilk text */
            text-decoration: none;
            font-weight: 600;
            font-size: 17px;
            padding: 10px 18px;
            border-radius: 50px;
            /* Pill shape */
            transition: all 0.3s ease;
            display: flex;
            align-items: center;
            gap: 10px;
            position: relative;
            overflow: hidden;
            /* Darker text shadow for contrast on the light text */
            text-shadow: 1px 1px 2px rgba(78, 52, 46, 0.5);
        }

        /* Hover Effect Background */
        nav ul li a::before {
            content: '';
            position: absolute;
            bottom: 0;
            left: 0;
            width: 100%;
            height: 0;
            /* Use a slightly transparent version of the text/border color for the fill */
            background-color: rgba(255, 248, 220, 0.2);
            /* Semi-transparent Cornsilk */
            border-radius: 50px;
            transition: height 0.3s cubic-bezier(0.175, 0.885, 0.32, 1.275);
            z-index: -1;
        }

        nav ul li a:hover {
            /* Make text slightly brighter or fully white on hover for pop */
            color: #FFFFFF;
            transform: translateY(-3px);
            /* Keep lift effect */
            /* Shadow matching the darker tones */
            box-shadow: 0 4px 8px rgba(78, 52, 46, 0.3);
        }

        nav ul li a:hover::before {
            height: 100%;
            /* Expand background fill */
        }

        /* Icon styling */
        nav ul li a i {
            font-size: 1.1em;
            transition: transform 0.3s ease;
            /* Icons inherit the link color (#FFF8DC) */
        }

        nav ul li a:hover i {
            transform: scale(1.2) rotate(10deg);
            /* Keep icon bounce/rotate */
        }
    </style>
</head>

<body>
    <header>
        <div class="nav-container">
            <div class="logo-container">
                <img src="{{ asset('images/logo.jpeg') }}" alt="RegiGate Logo" class="logo">
                <!-- Optional: Add Site Title (using header text color)
                 <span style="font-size: 1.5em; font-weight: 700; margin-left: 10px; text-shadow: 2px 2px 4px rgba(78,52,46,0.4);">RegiGate</span>
                 -->
            </div>
            <nav>
                <ul>
                    <!-- Language Dropdown -->
                    <li style="position: relative;">
                        <select onchange="window.location.href = this.value;" style="
                            padding: 10px 18px;
                            border-radius: 50px;
                            font-family: 'Poppins', sans-serif;
                            font-weight: 600;
                            font-size: 17px;
                            color: #FFF8DC;
                            background: rgba(255, 248, 220, 0.1);
                            border: 2px solid rgba(255, 248, 220, 0.3);
                            cursor: pointer;
                            transition: all 0.3s ease;
                            text-shadow: 1px 1px 2px rgba(78, 52, 46, 0.5);
                            appearance: none;
                            -webkit-appearance: none;
                            -moz-appearance: none;
                            padding-right: 35px;
                            background-image: url('data:image/svg+xml;utf8,<svg fill=\'%23FFF8DC\' height=\'24\' viewBox=\'0 0 24 24\' width=\'24\' xmlns=\'http://www.w3.org/2000/svg\'><path d=\'M7 10l5 5 5-5z\'/></svg>');
                            background-repeat: no-repeat;
                            background-position: right 10px center;
                        ">
                            <option value="{{ url('lang/en') }}" {{ app()->getLocale() == 'en' ? 'selected' : '' }}>English</option>
                            <option value="{{ url('lang/ar') }}" {{ app()->getLocale() == 'ar' ? 'selected' : '' }}>العربية</option>
                        </select>
                    </li>

                    <li><a href="{{ url('/') }}"><i class="fas fa-home fa-beat-fade"></i>@lang('messages.home')</a></li>
                    <li><a href="{{ url('/about') }}"><i class="fas fa-info-circle fa-spin"></i>@lang('messages.about')</a></li>
                    <li><a href="#contact"><i class="fas fa-envelope fa-bounce"></i>@lang('messages.contact')</a></li>
                </ul>
            </nav>
        </div>
    </header>


</body>

</html>
