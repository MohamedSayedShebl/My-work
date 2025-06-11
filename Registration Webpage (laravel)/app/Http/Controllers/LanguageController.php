<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\Support\Facades\Session;
use Illuminate\Support\Facades\App;

class LanguageController extends Controller
{
    public function change($locale)
    {
        // Validate if the locale is supported
        if (!in_array($locale, ['en', 'ar'])) {
            return redirect()->back();
        }

        // Store the locale in session
        Session::put('locale', $locale);

        // Set the application locale
        App::setLocale($locale);

        return redirect()->back();
    }
}
