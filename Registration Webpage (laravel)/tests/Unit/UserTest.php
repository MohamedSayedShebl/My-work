<?php

namespace Tests\Unit;

use Tests\TestCase;
use App\Mail\NewUserRegistered;
use Illuminate\Support\Facades\Mail;

class UserTest extends TestCase
{
    public function test_new_user_registered_email()
    {

        $username = 'DoniaKareem';
        $mail = new NewUserRegistered($username);

        $message = $mail->build();

        $this->assertEquals('asmaayasser200317@gmail.com', $message->from[0]['address']);
        $this->assertEquals($username, $message->from[0]['name']);
        $this->assertEquals('New registered user', $message->subject);
        $this->assertEquals('emails.email', $message->view);
        $this->assertArrayHasKey('username', $message->viewData);
        $this->assertEquals($username, $message->viewData['username']);
    }
}
