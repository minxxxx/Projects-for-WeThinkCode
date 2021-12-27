from django.db import models
from datetime import date


class Profile(models.Model):
    first_name = models.CharField(max_length=30)
    last_name = models.CharField(max_length=30)
    picture = models.ImageField(upload_to='image')
    intro = models.TextField(max_length=400)
    dob = models.DateField('date of birth')
    email = models.CharField(max_length=100)
    town = models.CharField(max_length=100)
    phone_nbr = models.CharField(max_length=13)

    def __str__(self):
        return self.first_name

    def age(self):
        today = date.today()
        years = int((today - self.dob).days / 365.2425)
        return years