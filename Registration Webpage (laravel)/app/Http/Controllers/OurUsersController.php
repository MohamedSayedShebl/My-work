<?php

namespace App\Http\Controllers;

use App\Models\our_users;
use App\Mail\NewUserRegistered;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Hash;

use Illuminate\Support\Facades\Mail;



class OurUsersController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $data = our_users::latest()->paginate(5);

        return view('index', compact('data'))->with('i', (request()->input('page', 1) - 1) * 5);
    }

    /**
     * Show the form for creating a new user.
     *
     * @return \Illuminate\Http\Response
     */


    public function create()
    {
        return view('create'); // Returns the view called create.blade.php.
    }

    /**
     * Store a newly created user in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */

    public function store(Request $request)
    {

        $request->validate([
            'fullName'        => 'required|string|max:200',
            'username'        => 'required|string|max:200|unique:our_users,user_name',
            'phone'           => 'required|string|max:20',
            'whatsAppNumber'  => 'required|string|max:20',
            'address'         => 'required|string',
            'email'           => 'required|email|max:200|unique:our_users,email',
            'password'        => [
                'required',
                'string',
                'min:8',
                'confirmed',
                'regex:/[0-9]/',         // At least one digit
                'regex:/[!@#$%^&*]/'     // At least one special character
            ],
            'image' => 'nullable|image|mimes:jpg,jpeg,png,gif|max:2048|dimensions:min_width=100,min_height=100,max_width=1000,max_height=1000',
        ]);

        // Store the uploaded image
        if ($request->hasFile('image')) {
            $imageName = time() . '.' . $request->image->getClientOriginalExtension();
            $request->image->move(public_path('images'), $imageName);
        }
        else {
            $imageName = 'default.jpg'; // or handle error
        }

        // Create and save the user
        $user = new our_users;
        $user->full_name       = $request->fullName;
        $user->user_name       = $request->username;
        $user->phone           = $request->phone;
        $user->whatsapp_number = $request->whatsAppNumber;
        $user->address         = $request->address;
        $user->email           = $request->email;
        $user->password        = Hash::make($request->password); // Laravel Encrypt password
        $user->user_image      = $imageName;

        $user->save();

        Mail::to('admin@example.com')->send(new NewUserRegistered($request->fullName));

        return redirect()->route('users.create')->with('Success', 'User added successfully.');
    }

    /**
     * Display the specified resource.
     *
     * @param  \App\Models\Student  $student
     * @return \Illuminate\Http\Response
     */

    /**
     * The show() function is responsible for:
     * Displaying the details of a single user
     * It receives a our_users model instance
     * Then it passes that user data to a Blade view named show.blade.php
     */
    public function show(our_users $user)
    {
        return view('show', compact('user'));
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  \App\Models\our_users  $user
     * @return \Illuminate\Http\Response
     */
    /**
     * The edit() function is responsible for:
     * Showing a form pre-filled with an existing user's data, so the user can edit and update it.
     * It receives the specific our_users model instance .
     * Then it loads the edit.blade.php view and passes the user data to it.
     */
    public function edit(our_users $user)
    {
        return view('edit', compact('user'));
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  \App\Models\Student  $student
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, our_users $user)
    {
        $request->validate([
            'full_name'      =>  'required',
            'email'     =>  'required|email',
            'user_image'     =>  'image|mimes:jpg,png,jpeg,gif,svg|max:2048|dimensions:min_width=100,min_height=100,max_width=1000,max_height=1000'
        ]);

        $user_image = $request->hidden_user_image;

        if($request->user_image != '')
        {
            $user_image = time() . '.' . request()->user_image->getClientOriginalExtension();

            request()->user_image->move(public_path('images'), $user_image);
        }

        $user = our_users::find($request->hidden_id);

        $user->student_name = $request->student_name;

        $user->student_email = $request->student_email;

        $user->student_gender = $request->student_gender;

        $user->student_image = $user_image;

        $user->save();

        return redirect()->route('/')->with('success', 'User Data has been updated successfully');
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  \App\Models\Student  $student
     * @return \Illuminate\Http\Response
     */
    public function destroy(our_users $student)
    {
        $student->delete();

        return redirect()->route('students.index')->with('success', 'Student Data deleted successfully');
    }

    public function verifyWhatsApp(Request $request)
    {
        if (!$request->has('whatsAppNumber') || empty($request->whatsAppNumber)) {
            return response()->json(['error' => 'Please enter a WhatsApp number.'], 400);
        }

        $whatsappNumber = $request->whatsAppNumber;
        $apiUrl = "https://whatsapp-number-validator3.p.rapidapi.com/WhatsappNumberHasItWithToken";
        $postData = json_encode(["phone_number" => $whatsappNumber]);

        // Abdo API Key: 3536f4e303msh8641134665eb3b3p110311jsn6ad8d53e9d16
        // Omar API Key: 17866e6b0bmsh460e6cdd9c2d14ap12acb7jsn3e2968d79057
        $headers = [
            "Content-Type: application/json",
            "x-rapidapi-host: whatsapp-number-validator3.p.rapidapi.com",
            "x-rapidapi-key: 3536f4e303msh8641134665eb3b3p110311jsn6ad8d53e9d16"
        ];

        $curl = curl_init();
        curl_setopt_array($curl, [
            CURLOPT_URL => $apiUrl,
            CURLOPT_RETURNTRANSFER => true,
            CURLOPT_CUSTOMREQUEST => "POST",
            CURLOPT_POSTFIELDS => $postData,
            CURLOPT_HTTPHEADER => $headers
        ]);

        $response = curl_exec($curl);
        $err = curl_error($curl);

        curl_close($curl);

        if ($err) {
            return response()->json(['error' => 'API request error: ' . $err], 500);
        }

        $result = json_decode($response, true);

        if (isset($result["status"]) && $result["status"] === "valid") {
            return response()->json(['status' => 'success', 'message' => 'Valid WhatsApp number.']);
        } else {
            return response()->json(['status' => 'error', 'message' => 'Invalid WhatsApp number.']);
        }
    }
}
