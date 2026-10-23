/*
  TVTest
  Copyright(c) 2008-2020 DBCTRADO

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/


#ifndef TVTEST_AUDIO_OPTIONS_H
#define TVTEST_AUDIO_OPTIONS_H


#include "Options.h"
#include "LibISDB/LibISDB/Windows/Viewer/ViewerFilter.hpp"
#include "LibISDB/LibISDB/Windows/Viewer/DirectShow/DirectShowUtilities.hpp"
#include <vector>


namespace TVTest
{

	class CAudioOptions
		: public COptions
	{
	public:
		struct AudioLanguageInfo
		{
			DWORD Language;
			bool fSub;

			bool operator==(const AudioLanguageInfo &Op) const noexcept = default;
		};

		typedef std::vector<AudioLanguageInfo> AudioLanguageList;

		using AACDecoderType = LibISDB::ViewerFilter::AACDecoderType;

		~CAudioOptions();

	// CSettingsBase
		bool ReadSettings(CSettings &Settings) override;
		bool WriteSettings(CSettings &Settings) override;

	// CBasicDialog
		bool Create(HWND hwndOwner) override;

	// CAudioOptions
		bool ApplyMediaViewerOptions();
		const String & GetAudioDeviceName() const { return m_AudioDevice.FriendlyName; }
		const String & GetAudioDeviceMoniker() const { return m_AudioDevice.MonikerName; }
		LPCTSTR GetAudioFilterName() const { return StringUtility::GetCStrOrNull(m_AudioFilterName); }
		AACDecoderType GetAACDecoder() const { return m_AACDecoder; }
		const LibISDB::DirectShow::AudioDecoderFilter::SPDIFOptions &GetSpdifOptions() const { return m_SPDIFOptions; }
		bool SetSpdifOptions(const LibISDB::DirectShow::AudioDecoderFilter::SPDIFOptions &Options);
		bool GetDownMixSurround() const { return m_fDownMixSurround; }
		int GetLatmDownmixChannels() const { return m_LatmDownmixChannels; }
		int GetAudioOutputMode() const { return m_AudioOutputMode; }
		// 空文字列の場合、GetLatmDownmixChannels()の値から決まる既定の
		// プリセット名("7.1ch"/"5.1ch"/"2ch")が使われる
		const String &GetLatmDownmixPresetName() const { return m_LatmDownmixPresetName; }
		bool GetEnableLanguagePriority() const { return m_fEnableLanguagePriority; }
		const AudioLanguageList &GetLanguagePriority() const { return m_LanguagePriority; }
		bool GetResetAudioDelayOnChannelChange() const { return m_fResetAudioDelayOnChannelChange; }

	private:
		class CSurroundOptionsDialog
			: public CBasicDialog
		{
		public:
			CSurroundOptionsDialog(CAudioOptions *pOptions);
			bool Show(HWND hwndOwner) override;

		private:
			CAudioOptions *m_pOptions;

			INT_PTR DlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
			void SetDownMixMatrix(const LibISDB::DirectShow::AudioDecoderFilter::DownMixMatrix &Matrix);
		};

		static const LibISDB::DirectShow::AudioDecoderFilter::SurroundMixingMatrix m_DefaultSurroundMixingMatrix;
		static const LibISDB::DirectShow::AudioDecoderFilter::DownMixMatrix m_DefaultDownMixMatrix;
		static const DWORD m_AudioLanguageList[];
		static constexpr DWORD LANGUAGE_FLAG_SUB = 0x01000000;

		using FilterInfo = LibISDB::DirectShow::FilterInfo;

		FilterInfo m_AudioDevice;
		String m_AudioFilterName;
		AACDecoderType m_AACDecoder = AACDecoderType::Default;

		LibISDB::DirectShow::AudioDecoderFilter::SPDIFOptions m_SPDIFOptions{
			LibISDB::DirectShow::AudioDecoderFilter::SPDIFMode::Disabled,
			LibISDB::DirectShow::AudioDecoderFilter::SPDIFOptions::Channel_Surround};
		bool m_fDownMixSurround = true;
		int m_LatmDownmixChannels = 8; // 22.2ch等のダウンミックス先。8=7.1ch, 6=5.1ch, 2=2ch, 0=行わない
		int m_AudioOutputMode = 0; // 22.2ch「ダウンミックスしない」時の出力方式。0=自動(空間オーディオ優先), 1=チャンネルマトリクスのみ
		// LatmDownmixPresets.iniで定義したプリセットを明示的に使う場合の名前。
		// 空文字列なら、ダウンミックス先ch数から決まる既定名("7.1ch"等)を使う
		String m_LatmDownmixPresetName;
		bool m_fUseCustomSurroundMixingMatrix = false;
		LibISDB::DirectShow::AudioDecoderFilter::SurroundMixingMatrix m_SurroundMixingMatrix{m_DefaultSurroundMixingMatrix};
		bool m_fUseCustomDownMixMatrix = false;
		LibISDB::DirectShow::AudioDecoderFilter::DownMixMatrix m_DownMixMatrix{m_DefaultDownMixMatrix};
		bool m_fEnableLanguagePriority = false;
		AudioLanguageList m_LanguagePriority;
		bool m_fResetAudioDelayOnChannelChange = true;

		std::vector<FilterInfo> m_AudioDeviceList;

	// CBasicDialog
		INT_PTR DlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) override;

		void GetLanguageText(DWORD Language, bool fSub, LPTSTR pszText, int MaxText) const;
		void UpdateLanguagePriorityControls();
	};

} // namespace TVTest


#endif
