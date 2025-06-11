<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration
{
    /**
     * Run the migrations.
     */
    public function up(): void
    {
        Schema::create('our_users', function (Blueprint $table) {
            $table->id();
            $table->string('full_name', 200);
            $table->string('user_name', 200);
            $table->string('phone', 20);
            $table->string('whatsapp_number', 20);
            $table->text('address'); // equivalent to TEXT in SQL
            $table->string('email', 200);
            $table->string('password', 200);
            $table->string('user_image', 250);
            $table->timestamps();
        });
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::dropIfExists('our_users');
    }
};
