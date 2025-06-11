<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class our_users extends Model
{
    /** @use HasFactory<\Database\Factories\OurUsersFactory> */
    use HasFactory;
    
    protected $fillable = ['full_name','user_name','phone','whatsapp_number','address','email','password','user_image'];
}
