from django.shortcuts import render, redirect
from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth.models import User
from django.contrib.auth import login, authenticate, logout
from .forms import RegistrationForm, CustomRegistrationForm
from django.contrib import messages

# Create your views here.

def sign_up(request):
    form = CustomRegistrationForm()
        
    if request.method == "POST":
        form = CustomRegistrationForm(request.POST)
        if form.is_valid():
            print(form.cleaned_data)
            user = form.save(commit = False)
            user.set_password(form.cleaned_data['password1'])   
            user.is_active = False
            user.save()
            
            messages.success(request, "A confirmation email has been sent to your email address.")
            return redirect("sign-in")
            
    return render(request,'registration/sign_up.html', {"form": form})


def sign_in(request):
    if request.method == 'POST':
        username = request.POST.get('username')
        password = request.POST.get('password')
        print("Doc", username, password)
        user = authenticate(request, username=username, password=password)
        print(user)
        if user is not None:
            login(request, user)
            return redirect('home')
    return render(request, 'registration/sign_in.html')


def sign_out(request):
    if request.method == 'POST':
        logout(request)
        return redirect('sign-in')