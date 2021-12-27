from Portfolio.models import Project


def portfolio():
    projects = Project.objects.all()
    return projects
