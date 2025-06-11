 <!-- This includes header.blade.php -->
@extends('layout.master')
@section('content')
    <section id="about" style="padding: 60px; text-align: center; background-color: #FAF0E6;">
        <h2 style="font-size: 2.5em; color: #8B4513;">About Us</h2>
        <p style="max-width: 800px; margin: 20px auto; font-size: 1.2em; line-height: 1.6; color: #5D4037;">
            Welcome to <strong>RegiGate</strong>, your trusted registration platform. Our mission is to simplify the registration process with efficiency and security.
        </p>

        <div style="display: flex; justify-content: center; align-items: center; margin-top: 30px;">
            <img src="{{ asset('images/logo.jpeg') }}" alt="About Us" style="width: 15%; border-radius: 15px; box-shadow: 0 4px 10px rgba(0,0,0,0.2);">
        </div>

        <div style="margin-top: 40px; display: flex; justify-content: center; gap: 30px; flex-wrap: wrap;">
            <div style="background: #8B4513; color: white; padding: 20px; border-radius: 10px; width: 250px; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">
                <i class="fas fa-lock" style="font-size: 2em;"></i>
                <h3>Secure</h3>
                <p>We prioritize security to keep your data safe.</p>
            </div>
            <div style="background: #A0522D; color: white; padding: 20px; border-radius: 10px; width: 250px; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">
                <i class="fas fa-clock" style="font-size: 2em;"></i>
                <h3>Fast</h3>
                <p>Instant and hassle-free registration experience.</p>
            </div>
            <div style="background: #D2691E; color: white; padding: 20px; border-radius: 10px; width: 250px; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">
                <i class="fas fa-thumbs-up" style="font-size: 2em;"></i>
                <h3>User-Friendly</h3>
                <p>Designed for ease of use and accessibility.</p>
            </div>
        </div>
    </section>
@endsection


