<?php

use App\Http\Controllers\OurUsersController;
use App\Http\Controllers\LanguageController;
use Illuminate\Support\Facades\Route;
use Illuminate\Http\Request;
use App\Models\our_users;



Route::get('/about', function () { return view('about'); });
Route::get('/check-username', function(Request $request) {
    $username = $request->get('username');
    $exists = our_users::where('user_name', $username)->exists();
    return response()->json(['exists' => $exists]);
});

Route::get('/', [OurUsersController::class, 'create'])->name('users.create');
Route::post('/', [OurUsersController::class, 'store'])->name('users.store');
Route::post('/verify-whatsapp', [OurUsersController::class, 'verifyWhatsApp'])->name('verify.whatsapp');

Route::get('lang/{locale}', [LanguageController::class, 'change']);
