from django.db import models

# Create your models here. that is table

class Project(models.Model):
    name = models.CharField(max_length=200)
    description = models.TextField(blank=True, null=True)
    start_date = models.DateField()
    
    def __str__(self):
        return self.name


class Employee(models.Model):
    name = models.CharField(max_length=200)
    email = models.EmailField(unique=True)
    
    # dander method
    def __str__(self):
        return self.name


class Task(models.Model):
    STATUS_CHOICES = [
        ("PENDING", "Pending"),
        ("IN_PROGRESS", "In Progress"),
        ("COMPLETED", "Completed"),
    ]
    project = models.ForeignKey("Project", on_delete=models.CASCADE, default=1)
    # notun_string = models.CharField(max_length=200, default="")
    assigned_to = models.ManyToManyField(Employee, related_name='tasks')
    title = models.CharField(max_length=200)
    description =  models.TextField()
    due_date = models.DateField()
    status = models.CharField(max_length=20, choices=STATUS_CHOICES, default="PENDING")
    is_completed = models.BooleanField(default=False)
    created_at = models.DateField(auto_now_add=True)
    updated_at = models.DateField(auto_now=True)
    
    def __str__(self):
        return self.title
    
    
class TaskDetail(models.Model):
    HIGH = 'HIGH'
    MEDIUM = 'MEDIUM'
    LOW = 'LOW'
    
    PRIORITY_OPTIONS = [
        (HIGH, "High"),
        (MEDIUM, "Medium"),
        (LOW, "Low"),
    ]
    task = models.OneToOneField(Task, on_delete=models.CASCADE, related_name='details',)
    assigned_to = models.CharField(max_length=100)
    priority = models.CharField(max_length=6, choices=PRIORITY_OPTIONS, default=LOW)
    notes = models.TextField(blank = True, null=True)
    
    def __str__(self):
        return f"Details form Task {self.task.title}"


# Task.objects.get(id=2)
# select * from task where id = 2
# ORM = Object Relational Mapping



