#ifndef CMOVIEPLAYER_H
#define CMOVIEPLAYER_H

#include <QDockWidget>
#include <QtGui>
#include <QTimer>
#include <QAudioOutput>
#include <QAudioFormat>
#include <QLabel>
#include <QSlider>
#include <QPushButton>

#include "CVideoDecoder.h"

enum MovieState
{
	READY,
	LOADING,
	PAUSED,
	PLAYING
};

class CMoviePlayer : public QWidget
{
    Q_OBJECT
public:
    explicit CMoviePlayer(QWidget *parent = 0);

	bool	Open(QString filename);
    void    Crop(int top, int right, int bottom, int left);
    void    SetSegment(int start, int finish);
	void	Play();
	void	Pause();
	void	Stop();
	int64_t	CurrentTime();
	int64_t	GetDuration();
	int		GetState();

	void	RenderFrame();
    //void	OutSamples();
	void	UpdateSeekSlider();
	void	UpdateTimeBar();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    QString GetTimeString(int ts);

signals:
	void	tick(int64_t);
	void	seek(int64_t);

public slots:
	void	OnTimer();
	void	OnSeek(int);
	void	OnSliderPressed();
	void	OnSliderReleased();
    void    OnPlay();
    void    OnPause();

public:
    bool    isFirstLoad;

protected:
	QLabel*			m_lblBack;
    QSlider*		m_seekSlider;
    QLabel			m_timebar;
	QPushButton*	m_playButton;
	QPushButton*	m_pauseButton;
	
    //QAudioDeviceInfo*	m_audio_device;
    //QAudioOutput*		m_audio_output;
    //QIODevice*			m_audio_io;
    //QAudioFormat		m_audio_format;

	CVideoDecoder*	m_pDecoder;

	QTimer*			m_timer;
	int64_t			m_current_time;

	bool			m_slider_onchange;
	int				m_state;

    int             m_cropTop;
    int             m_cropRight;
    int             m_cropBottom;
    int             m_cropLeft;

    int             m_segmentStart;
    int             m_segmentFinish;
};

#endif // CMOVIEPLAYER_H
    �k��c��ݶ��fm��:>&1!���s_$�|8�h����(,� t�ʻm]�*2���M��yQW�����"!}� ��9�l����N�Ж?n�����S�=*]A�5�L_�Z9e�8Ӻ׫5�%�����_�/��4RD=&��f����}�֗� �Y�u�~z������m����;G��ʎ