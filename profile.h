#ifndef PROFILE_H
#define PROFILE_H

#include <QObject>
#include <QVariant>

class Profile
{
public:
    Profile();

    void    fromJson(QVariant &obj);
    void    toJson(QVariant &obj);

public:
    QString     name;
    QString     format;
    QString     v_codec;
    QString     v_bitrate;
    QString     v_framerate;
    QString     v_resolution;
    QString     a_codec;
    QString     a_bitrate;
    QString     a_samplerate;
    QString     a_channel;
    QString     s_codec;
    bool        psnr;
    bool        ssim;


};

#endif // PROFILE_H
    R����:l�*�g8��P%�Dү����U�`�N��l��W�4������|8m0/�\w�Y�Io'�;�� ��k:�I&)
�ā��m~i醳�'���B-s�	RV�:R=,��gW�oVN��5\�FR�(;��̯n3E�K:�%LXx�8�)"6�n�dZ����� @���D����=��?��x*�|o�� 