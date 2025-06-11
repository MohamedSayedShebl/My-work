<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="csrf-token" content="{{ csrf_token() }}">
    <title>@yield('title', 'RegiGate')</title>
    <link rel="stylesheet" href="{{ asset('css/index.css') }}">
</head>
<body>
    @include('partials.header')
    @yield('content')
    <script src="{{ asset('js/whatsapp-verification.js') }}"></script>
    <script src="{{ asset('js/create.js') }}"></script>
    @include('partials.footer')
</body>
</html>