from django.shortcuts import render
from django.http import HttpResponse
from tasks.forms import TaskForm, TaskModelForm
from tasks.models import *
from datetime import date
from django.db.models import Q

# Create your views here.

def manager_dashboard(request):
    return render(request,'dashboard/manager-dashboard.html')

def user_dashboard(request):
    return render(request,'dashboard/user-dashboard.html')

def test(request):
    context = {
        "names": ["Mahmud", "Ahamed", "John", "Sarah", "Emily"],
        "age": 23
    }
    return render(request,'test.html',context)

def create_task(request):
    # employees = Employee.objects.all()
    form = TaskModelForm()
    
    if request.method == "POST":
        form = TaskModelForm(request.POST)
        if form.is_valid():
            '''For Model form data'''
            form.save()
            return render(request,'task_form.html', {"form": form, "message": "Task created successfully"})
        
        
            '''For Django form data'''
            # data = form.cleaned_data
            # title = data.get("title")
            # description = data.get("description")
            # due_date = data.get("due_date")
            # assigned_to = data.get("assigned_to")
            
            # task = Task.objects.create(title = title, description = description, due_date = due_date)
            # task.assigned_to.set(assigned_to)
            
            # # Assign employee to tasks
            # for emp_id in assigned_to:
            #     employee = Employee.objects.get(id=emp_id)
            #     employee.tasks.add(task)
            
            # return HttpResponse("Task created successfully")
            
    context = {"form": form}
    return render(request,'task_form.html',context)


def view_task(request):
    
    all_tasks = Task.objects.all()
    
    # retrieve a specific task
    specific_task = Task.objects.get(pk=1)
    
    # fetch 1st task
    first_task = Task.objects.first()
    
    # fetch last task
    last_task = Task.objects.last()
    
    # using filter method showing completed tasks
    completed_tasks = Task.objects.filter(status="COMPLETED")
    
    # using exclude method
    pending_tasks = Task.objects.exclude(is_completed=True, status="PENDING")
    
    tasks_date = Task.objects.filter(due_date = date(2025,1,19))
    
    # using priority filter
    high_priority_tasks = TaskDetail.objects.exclude(priority__in=["L","M"])
    
    
    '''Show word that contain c'''
    tasks_word = Task.objects.filter(title__icontains="c")
    
    return render(request, "show_task.html", {
        "tasks": all_tasks, "task3": specific_task, "task1": first_task, "task2": last_task,
        "completed_tasks": completed_tasks, "pending_tasks": pending_tasks, "tasks_date": tasks_date,
        "high_priority_tasks": high_priority_tasks, "tasks_word": tasks_word
        })



