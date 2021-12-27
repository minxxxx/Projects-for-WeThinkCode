from Presentation.models import Profile


def presentation():
    profiles = Profile.objects.all()
    return profiles
