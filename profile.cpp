#include "profile.h"
#include "json.h"

using QtJson::JsonObject;
using QtJson::JsonArray;

Profile::Profile()
{
}

void Profile::fromJson(QVariant &obj)
{
    JsonObject p = obj.toMap();
    name = p["name"].toString();
    format = p["format"].toString();

    v_codec = p["v_codec"].toString();
    v_bitrate = p["v_bitrate"].toString();
    v_framerate = p["v_framerate"].toString();
    v_resolution = p["v_resolution"].toString();

    a_codec = p["a_codec"].toString();
    a_bitrate = p["a_bitrate"].toString();
    a_samplerate = p["a_samplerate"].toString();
    a_channel = p["a_channels"].toString();

    s_codec = p["s_codec"].toString();

    psnr = p["psnr"].toBool();
    ssim = p["ssim"].toBool();
}

void Profile::toJson(QVariant &obj)
{    
    JsonObject p = obj.toMap();

    p["name"] = name;
    p["format"] = format;
    p["v_codec"] = v_codec;
    p["v_bitrate"] = v_bitrate;
    p["v_framerate"] = v_framerate;
    p["v_resolution"] = v_resolution;
    p["a_codec"] = a_codec;
    p["a_bitrate"] = a_bitrate;
    p["a_samplerate"] = a_samplerate;
    p["a_channels"] = a_channel;
    p["s_codec"] = s_codec;
    p["psnr"] = psnr;
    p["ssim"] = ssim;

    obj = QVariant(p);
}
    �Ü7<QO0ݯ���&��M�g����"�&�L����"e���%�&��sZ�9�(��BN'4�,���nN�qL��|E�+9�?SwEZ��C3�'SBh���ti2� ��Q�4ӓy)�E'"yN(2|:w�Y�dҮ�k���.e�%��󚯋��h�|�d�Ux�\6bh"�N�@oY�h