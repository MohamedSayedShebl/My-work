<?php

namespace Tests\Feature;
use Tests\TestCase;
use App\Models\our_users;
use Illuminate\Foundation\Testing\RefreshDatabase;

class UserRegisteredTest extends TestCase
{
    use RefreshDatabase;
    /**
     * Test creating a new user successfully.
     * @return void
     */
    public function test_create_new_user_successfully()
    {
        $userData = [
            'fullName' => 'Donia Kareem',
            'username' => 'deda123',
            'phone' => '01119012042',
            'whatsAppNumber' => '+201119012042',
            'address' => 'harm',
            'email' => 'donia111@gmail.com',
            'password' => '1234#@donia',
            'password_confirmation' => '1234#@donia',
        ];

        $response = $this->post(route('users.store'), $userData);

        $response->assertStatus(302);
        $response->assertRedirect(route('users.create'));

        $this->get(route('users.create'))->assertSee('User added successfully');
        $this->assertDatabaseHas('our_users', [
            'full_name' => 'Donia Kareem',
            'email' => 'donia111@gmail.com',
            'user_image' => 'default.jpg',
        ]);
    }
    /**
     * Test WhatsApp number validation with a valid number.
     * @return void
     */
    public function test_verify_whatsapp_valid_number()
    {
        $validWhatsAppNumber = '+201119012042';

        $response = $this->postJson(route('verify.whatsapp'),
            ['whatsAppNumber' => $validWhatsAppNumber]);

        $response->assertStatus(200);
        $response->assertJson([
            'status' => 'success',
            'message' => 'Valid WhatsApp number.'
        ]);
    }

    /**
     * Test WhatsApp number validation with missing input.
     * @return void
     */
    public function test_verify_whatsapp_missing_number()
    {
        $response = $this->postJson(route('verify.whatsapp'), []);

        $response->assertStatus(400);
        $response->assertJson([
            'error' => 'Please enter a WhatsApp number.'
        ]);
    }

    /**
     * Test the about page content with see and dont see.
     * @return void
     */
    public function test_about_page_content_with_see_and_dont_see()
    {
        $response = $this->get('/about');

        $response->assertStatus(200);

        $response->assertSee('RegiGate');
        $response->assertSee('About Us');
        $response->assertSee('Secure');
        $response->assertSee('Fast');
        $response->assertSee('User-Friendly');

        $response->assertDontSee('Login');
    }
}




