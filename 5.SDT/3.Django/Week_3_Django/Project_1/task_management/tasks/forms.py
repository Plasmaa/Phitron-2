from django import forms
from tasks.models import Task

# Django Form
class TaskForm(forms.Form):
    title = forms.CharField(max_length=200, label="Task Title")
    description = forms.CharField(widget=forms.Textarea, label="Description")
    # due_date = forms.DateField(widget=forms.DateInput(attrs={'type': 'date'}))
    due_date = forms.DateField(widget=forms.SelectDateWidget(attrs={'type': 'date'}))
    assigned_to = forms.MultipleChoiceField(widget=forms.CheckboxSelectMultiple, choices=[], label="Assigned To")
    
    def __init__(self, *args, **kwargs):
        # print(args,kwargs)
        employees = kwargs.pop('employees', [])
        super().__init__(*args, **kwargs)
        self.fields['assigned_to'].choices = [(emp.id, emp.name) for emp in employees] 
        

class StyledFormMixin:
    '''Mixing to apply style to form fields'''
    default_classes = "border-2 border-gray-600 w-full p-3 rounded-lg shadow-sm focus:border-rose-300 focus: ring-red-400"
    default_classes2 = 'border-2 border-gray-600 rounded-lg shadow-sm focus:border-rose-300 focus: ring-red-400'
    def apply_styled_widgets(self):
        for field_name, field in self.fields.items():
            if isinstance(field.widget, forms.TextInput):
                field.widget.attrs.update({
                    'class': self.default_classes,
                    'placeholder': f"Enter {field.label.lower()}"
                })
            elif isinstance(field.widget, forms.Textarea):
                field.widget.attrs.update({
                    'class': self.default_classes,
                    'placeholder': f"Describe the {field.label.lower()}",
                    'rows': 5
                })
                
            elif isinstance(field.widget, forms.SelectDateWidget):
                field.widget.attrs.update({
                    'class': self.default_classes2
                })
            elif isinstance(field.widget, forms.CheckboxSelectMultiple):
                field.widget.attrs.update({
                    'class': 'rounded-lg shadow-sm focus:border-rose-300 focus: ring-red-400'
                })
            # else:
            #     field.widget.attrs.update({
            #         'class': self.default_classes
            #     })

# Django ModelForm
class TaskModelForm(StyledFormMixin, forms.ModelForm):
    class Meta:
        model = Task
        fields = ['title', 'description', 'due_date', 'assigned_to']
        widgets = {
            'due_date': forms.SelectDateWidget,
            'assigned_to': forms.CheckboxSelectMultiple
        }
        # exclude = ['project', 'is_completed', 'created_at', 'updated_at']
        
        
        '''Manual Widget'''
        # widgets = {
        #     'title' : forms.TextInput(attrs={
        #         'placeholder': 'Enter task title...',
        #         'class': 'border-2 border-gray-600 w-full p-3 rounded-lg shadow-sm focus:border-rose-300 focus: ring-red-400'
        #         }),
        #     'description': forms.Textarea(attrs={
        #         'placeholder': 'Describe the task...',
        #         'class': 'border-2 border-gray-600 w-full p-3 rounded-lg shadow-sm focus:border-rose-300 focus: ring-red-400',
        #         'rows': 5,
        #         }),
        #     'due_date': forms.SelectDateWidget(attrs={
        #         'class': 'border-2 border-gray-600 rounded-lg shadow-sm focus:border-rose-300 focus: ring-red-400'
        #         }),
        #     'assigned_to': forms.CheckboxSelectMultiple(attrs={
        #         'class': 'rounded-lg shadow-sm focus:border-rose-300 focus: ring-red-400'
        #         })
        # }
        
    '''Using Mixing Widget'''
        
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.apply_styled_widgets()
