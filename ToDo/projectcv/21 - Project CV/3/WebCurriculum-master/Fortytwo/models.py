from django.db import models

#
# class ProjectFT(models.Model):
#     name = models.CharField()
#     grade = models.PositiveSmallIntegerField()
#     locked_at = models.DateField()
#     closed_at = models.DateField()
#     team_work = models.BooleanField()
#
#
# class SkillFT(models.Model):
#     name = models.CharField()
#     grade = models.DecimalField()
#
#
# class ProfileFT(models.Model):
#     level = models.DecimalField
#     grade = models.CharField
#     skills = models.ManyToManyField(ProjectFT)
#     projects = models.ManyToManyField(SkillFT)