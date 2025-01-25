from django.shortcuts import render
from django.http import HttpResponse
from tasks.forms import TaskForm, TaskModelForm
from tasks.models import *
from datetime import date
from django.db.models import Q, Count, Sum, Avg, Max, Min

# Create your views here.

def manager_dashboard(request):
    type = request.GET.get("type", "all")
    
    counts = Task.objects.aggregate(
        total=Count('id'),
        completed=Count('id', filter=Q(status="COMPLETED")),
        pending=Count('id', filter=Q(status="PENDING")),
        in_progress=Count('id', filter=Q(status="IN_PROGRESS")),
    )
    
    # retrieving task data
    base_query = Task.objects.select_related("details").prefetch_related("assigned_to")
    
    if type == "completed":
        tasks = base_query.filter(status="COMPLETED")
    elif type == "pending":
        tasks = base_query.filter(status="PENDING")
    elif type == "in_progress":
        tasks = base_query.filter(status="IN_PROGRESS")
    else:
        tasks = base_query.all()
    
    
    context = {
        "tasks": tasks,
        "counts": counts
    }
    
    return render(request,'dashboard/manager-dashboard.html', context)

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



