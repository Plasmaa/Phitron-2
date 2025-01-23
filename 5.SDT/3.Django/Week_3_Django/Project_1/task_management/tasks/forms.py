from django import forms

class TaskForm(forms.Form):
    title = forms.CharField(max_length=200, label="Task Title")
    description = forms.CharField(widget=forms.Textarea, label="Description")
    due_date = forms.DateField(widget=forms.DateInput(attrs={'type': 'date'}))
    # due_date = forms.DateField(widget=forms.SelectDateWidget(attrs={'type': 'date'}))
    assigned_to = forms.MultipleChoiceField(widget=forms.CheckboxSelectMultiple, choices=[])
    
    def __init__(self, *args, **kwargs):
        # print(args, kwargs)
        super().__init__(*args, **kwargs)
        
        