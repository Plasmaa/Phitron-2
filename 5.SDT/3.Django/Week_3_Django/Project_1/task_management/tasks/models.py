from django.db import models

# Create your models here. that is table

class Project(models.Model):
    name = models.CharField(max_length=200)
    start_date = models.DateField()


class Employee(models.Model):
    name = models.CharField(max_length=200)
    email = models.EmailField(unique=True)


class Task(models.Model):
    project = models.ForeignKey("Project", on_delete=models.CASCADE, default=1)
    # notun_string = models.CharField(max_length=200, default="")
    assigned_to = models.ManyToManyField(Employee, related_name='tasks')
    title = models.CharField(max_length=200)
    description =  models.TextField()
    due_date = models.DateField()
    is_completed = models.BooleanField(default=False)
    created_at = models.DateField(auto_now_add=True)
    updated_at = models.DateField(auto_now=True)
    
    
class TaskDetail(models.Model):
    HIGH = 'HIGH'
    MEDIUM = 'MEDIUM'
    LOW = 'LOW'
    
    PRIORITY_OPTIONS = [
        (HIGH, "High"),
        (MEDIUM, "Medium"),
        (LOW, "Low"),
    ]
    task = models.OneToOneField(Task, on_delete=models.CASCADE, related_name='details')
    assigned_to = models.CharField(max_length=100)
    priority = models.CharField(max_length=6, choices=PRIORITY_OPTIONS, default=LOW)


# Task.objects.get(id=2)
# select * from task where id = 2
# ORM = Object Relational Mapping


