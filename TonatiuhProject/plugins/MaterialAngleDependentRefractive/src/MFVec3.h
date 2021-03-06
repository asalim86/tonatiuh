/*
 * v.h
 *
 *  Created on: 27/11/2015
 *      Author: amutuberria
 */

#ifndef MFVEC3_H_
#define MFVEC3_H_

#include <QStringList>

#include <Inventor/SbVec3d.h>

#include <Inventor/fields/SoSubField.h>

#include "ContainerEditorMFVec3.h"
#include "FieldEditor.h"
#include "UserMField.h"


#if unix//( defined(Q_WS_X11) || defined(Q_WS_MAC) )

	class MFVec3 : public UserMField
	{
		  typedef UserMField inherited;
		  SO_MFIELD_HEADER( MFVec3, SbVec3d, const SbVec3d &);



	public:
	  static void initClass(void);

	  void setValues(int start, int num, const double xyz[][3]);
	  void set1Value(int idx, double x, double y, double z);
	  void set1Value(int idx, const double xyz[3]);
	  void setValue(double x, double y, double z);
	  void setValue(const double xyz[3]);


		QStringList GetNames( ) const;
		void SetNames( QString firstDimension, QString secondDimension, QString thirdDimension );

		FieldEditor* GetEditor() const
		{
			ContainerEditorMFVec3* editor = new ContainerEditorMFVec3();
			editor->SetTitles( GetNames() );
			return (editor) ;
		}

	private:
		QString m_firstDimensionName;
		QString m_secondtDimensionName;
		QString m_thirdDimensionName;
		FieldEditor* m_pEditor;
	};

#else

	#include <Inventor/SbVec3f.h>
	class MFVec3 : public UserMField
	{
		typedef UserMField inherited;

		  SO_MFIELD_HEADER(MFVec3, SbVec3f, const SbVec3f &);

	public:
		  static void initClass(void);

		  void setValues(int start, int num, const float xyz[][3]);
		  void set1Value(int idx, float x, float y, float z);
		  void set1Value(int idx, const float xyz[3]);
		  void setValue(float x, float y, float z);
		  void setValue(const float xyz[3]);


		QStringList GetNames( ) const;
		void SetNames( QString firstDimension, QString secondDimension, QString thirdDimension );

		FieldEditor* GetEditor() const
		{
			ContainerEditorMFVec3* editor = new ContainerEditorMFVec3();
			editor->SetTitles( GetNames() );
			return (editor) ;
		}

	private:
		QString m_firstDimensionName;
		QString m_secondtDimensionName;
		QString m_thirdDimensionName;
		FieldEditor* m_pEditor;
	};

#endif


#endif /* MFVEC3_H_ */
