# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Profile',
            fields=[
                ('id', models.AutoField(serialize=False, auto_created=True, primary_key=True, verbose_name='ID')),
                ('first_name', models.CharField(max_length=30)),
                ('last_name', models.CharField(max_length=30)),
                ('picture', models.ImageField(upload_to='image')),
                ('intro', models.TextField(max_length=400)),
                ('dob', models.DateField(verbose_name='date of birth')),
                ('email', models.CharField(max_length=100)),
                ('town', models.CharField(max_length=100)),
                ('phone_nbr', models.CharField(max_length=13)),
            ],
        ),
    ]
