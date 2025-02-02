from django.shortcuts import render, redirect, HttpResponse
from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth.models import User
from django.contrib.auth import login, authenticate, logout
from .forms import RegistrationForm, CustomRegistrationForm
from django.contrib import messages
from users.forms import LoginForm
from django.contrib.auth.tokens import default_token_generator

# Create your views here.

def sign_up(request):
    form = CustomRegistrationForm()
        
    if request.method == "POST":
        form = CustomRegistrationForm(request.POST)
        if form.is_valid():
            print(form.cleaned_data)
            user = form.save(commit = False)
            user.set_password(form.cleaned_data['password'])   
            user.is_active = False
            user.save()
            
            messages.success(request, "A confirmation email has been sent to your email address.")
            return redirect("sign-in")
            
    return render(request,'registration/sign_up.html', {"form": form})
def activate_user(request,user_id,token):
    try:
        user = User.objects.get(id=user_id)
        if default_token_generator.check_token(user, token):
            user.is_active = True
            user.save()
            login(request, user)
            return redirect("sign-in")
        else:
            return HttpResponse("invalid id or token")
    except User.DoesNotExist:
        return HttpResponse("User not found")


def sign_in(request):
    form = LoginForm()
    
    if request.method == 'POST':
        form = LoginForm(data=request.POST)
        if form.is_valid():
            user = form.get_user()
            login(request, user)
            return redirect('home')
    return render(request, 'registration/sign_in.html', {'form': form})


def sign_out(request):
    if request.method == 'POST':
        logout(request)
        return redirect('sign-in')